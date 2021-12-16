#include "Player.hpp"
#include "Hero.hpp"
#include "Sub_Hero.hpp"
#include "Enemy.hpp"
#include <stack>
#include <memory>

int game(Hero &hero, Enemy &enemy, std::ostream &fout){
    int opt, hit_counter = 0, chance, pot;
    const static int POTION_REWARD = 4; //how many attacks before the hero is given a potion
    const static int POTION_CHANCE = 70; //chance to give the hero either a small or a big potion

    const static int max_st = hero.getStamina();

    while(1){
        std::cout <<"------------------------" <<std::endl
        <<hero.getName() <<" is fighting " <<enemy.getName() <<"!" <<std::endl
        <<"1) Check STATS" <<std::endl
        <<"2) Check ENEMY STATS" <<std::endl
        <<"3) ATTACK "<<enemy.getName() <<std::endl
        <<"4) PARRY incoming attack" <<std::endl
        <<"5) HEAL yourself using potions" <<std::endl
        <<"> ";

        std::cin >>opt;

        std::cout <<"------------------------" <<std::endl;

        switch(opt) {
            case(1):
                std::cout <<hero;
                break;
            case(2):
                std::cout <<enemy;
                break;
            case(3):
                //call attack function as long as you have stamina left
                if(hero.getStamina() > 0){
                    hero.attackEnemy(enemy, fout);
                    hit_counter++;
                    fout <<"------------------------" <<std::endl;

                    //cut stamina by 10 points (Hero::Stamina should be divisible by 10)
                    hero.decreaseStamina();
                }
                else{
                    std::cout <<"You ran out of stamina! Wait for it to regenerate..." <<std::endl;
                }

                //give potion to hero and reset counter
                chance = rand() % 101;
                if(hit_counter == POTION_REWARD){
                    if(chance <= POTION_CHANCE){
                        hero.give_potion("small_hp");
                        std::cout <<"------------------------" <<std::endl
                        <<"You were given a SMALL healing potion!" <<std::endl;
                    }
                    else{
                        hero.give_potion("big_hp");
                        std::cout <<"------------------------" <<std::endl
                        <<"You were given a BIG healing potion!" <<std::endl;
                    }
                    hit_counter = 0;
                }

                //return to main menu if enemy is killed
                if(enemy.getHP() <= 0)
                    return 1;
                break;
            case(4):
                ///temporarily buffs the hero's defence stat using the Hero::parryAttack function
                ///before attacking
                hero.parryAttack("buff");
                enemy.attackEnemy(hero, fout);

                //for logging
                fout <<"------------------------" <<std::endl;

                hero.parryAttack("debuff");

                //regen hero's stamina by 10 points
                if(hero.getStamina() <= max_st)
                    hero.increaseStamina();

                //return to main menu if hero is killed
                if(hero.getHP() <= 0)
                    return 0;
                break;
            case(5):
                std::cout <<"Consume a SMALL potion (1) or a BIG potion (2)?" <<std::endl
                <<"> ";

                std::cin >>pot;
                
                int potion_result = hero.heal(pot);
                if(potion_result == -1){
                    std::cout <<"------------------------" <<std::endl 
                    <<"Can't heal, HP is maxed out!" <<std::endl;
                }
                else if(potion_result == -2){
                    std::cout <<"------------------------" <<std::endl 
                    <<"You don't have potions of that type!" <<std::endl;
                }
                else{
                    std::cout <<"------------------------" <<std::endl
                    <<"You healed yourself for " <<potion_result <<"!" <<std::endl;
                }

                break;
        }
    }
}

int start(Hero &hero, std::stack< std::unique_ptr<Enemy> > &enemy_stack, std::ostream &fout){
    int opt, result, init_stamina;
    init_stamina = hero.getStamina();

    while(1){
        std::cout <<"------------------------" <<std::endl;
        std::cout <<"Choose an option:" <<std::endl;
        std::cout <<"1) Check STATS" <<std::endl;
        std::cout <<"2) FIGHT enemies" <<std::endl;
        std::cout <<"3) QUIT game" <<std::endl;
        std::cout <<"> ";

        std::cin >>opt;

        std::cout <<"------------------------" <<std::endl;

        switch(opt) {
            case(1):
                std::cout <<hero;
                break;
            case(2):
                //fight enemies from the stack until either the stack is empty or you die
                result = game(hero, *enemy_stack.top(), fout);
                if(result == 0){
                    std::cout <<std::endl <<"You were killed. Game over!" <<std::endl;
                    return 1;
                }
                else{
                    std::cout <<"------------------------";
                    std::cout <<std::endl <<"You killed " <<enemy_stack.top()->getName() <<std::endl;

                    hero.setStamina(init_stamina);
                    enemy_stack.pop();

                    //if you killed all the enemies, return to main
                    if(enemy_stack.empty() == 1){
                        std::cout <<std::endl <<"You killed all the enemies! You win!" <<std::endl;
                        return 1;
                    }
                }
                break;
            case(3):
                std::cout <<"You quit the game. :(" <<std::endl;

                //return to main after result
                return 1;
        }
    }
}

int main(){
    //time seed for random number generator
    srand(time(NULL));

    //enemies declaration
    std::stack< std::unique_ptr<Enemy> > enemy_stack;
    enemy_stack.push(std::make_unique<Enemy>("Brutus"));
    enemy_stack.push(std::make_unique<Enemy>("Leroy"));

    //hero declaration
    Hero hero;
    
    //check hero for errors after constructing
    try {
        std::cin >>hero;
    }catch(TypeException &e){
        std::cout <<"heroException caught: " <<e.what() <<std::endl;
        return 0;
    }
    
    //check hero for errors after assigning a subclass
    try {
        if(hero.getType() == "Basic" || hero.getType() == "basic"){
            basicHero subhero(hero.getName(), hero.getType());
            hero = subhero;
        }
        if(hero.getType() == "Light" || hero.getType() == "light"){
            lightHero subhero(hero.getName(), hero.getType());
            hero = subhero;
        }
        if(hero.getType() == "Heavy" || hero.getType() == "heavy"){
            heavyHero subhero(hero.getName(), hero.getType());
            hero = subhero;
        }
    }catch(StatsException &e){
        std::cout <<"heroException caught: " <<e.what() <<std::endl;
        return 0;
    }
    
    //open file for logging
    std::ofstream fout;
    fout.open("game_logs.out");

    //main menu
    start(hero, enemy_stack, fout);

    //close logging
    fout.close();

    return 0;
}