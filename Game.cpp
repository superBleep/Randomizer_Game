#include "Hero.hpp"
#include "Enemy.hpp"
#include "Boss.hpp"

template <typename T>
int game(Hero &hero, T &enemy, std::ostream &fout) {
    int opt, hit_counter = 0, chance, pot;
    const static int POTION_REWARD = 4; //how many attacks before the hero is given a potion
    const static int POTION_CHANCE = 70; //chance to give the hero either a small or a big potion

    const static int max_st = hero.getStamina();

    while(1){
        std::cout <<"------------------------" <<std::endl
        <<hero.getName() <<" is fighting " <<enemy.getName() <<"!" <<std::endl
        <<"1) Check STATS" <<std::endl;

        if(std::is_same<T, Enemy>::value == true)
            std::cout <<"2) Check ENEMY STATS" <<std::endl;
        else
            std::cout <<"2) Check BOSS STATS" <<std::endl;
        
        std::cout <<"3) ATTACK "<<enemy.getName() <<std::endl
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