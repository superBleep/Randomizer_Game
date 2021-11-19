#include "Player.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"

int game(Hero &hero, Enemy &enemy, std::ostream &fout){
    int opt;
    while(1){
        std::cout <<"------------------------" <<std::endl;
        std::cout <<hero.getName() <<" is fighting " <<enemy.getName() <<"!" <<std::endl;
        std::cout <<"1) Check STATS" <<std::endl;
        std::cout <<"2) Check ENEMY STATS" <<std::endl;
        std::cout <<"3) ATTACK "<<enemy.getName() <<std::endl;
        std::cout <<"4) PARRY incoming attack" <<std::endl;
        std::cout <<"> ";

        std::cin >>opt;

        std::cout <<"------------------------" <<std::endl;

        int max_st = hero.getStamina();

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
                    fout <<"------------------------" <<std::endl;

                    //cut stamina by 10 points (Player::Stamina should be divisible by 10)
                    hero.setStamina(hero.getStamina() - 10);
                }
                else{
                    std::cout <<"You ran out of stamina! Wait for it to regenerate..." <<std::endl;
                }

                //return to main menu if enemy is killed
                if(enemy.getHP() <= 0)
                    return 1;
                break;
            case(4):
                ///temporarily buffs the player's defence stat using the Player::parryAttack function
                ///before attacking
                hero.parryAttack("buff");
                enemy.attackEnemy(hero, fout);

                //for logging
                fout <<"------------------------" <<std::endl;

                hero.parryAttack("debuff");

                //regen player's stamina by 10 points
                if(hero.getStamina() <= max_st)
                    hero.setStamina(hero.getStamina() + 10);

                //return to main menu if player is killed
                if(hero.getHP() <= 0)
                    return 0;
                break;
        }
    }
}

int start(Hero &hero, Enemy &enemy, std::ostream &fout){
    int opt;
    while(1){
        std::cout <<"------------------------" <<std::endl;
        std::cout <<"Choose an option:" <<std::endl;
        std::cout <<"1) Check STATS" <<std::endl;
        std::cout <<"2) FIGHT enemy" <<std::endl;
        std::cout <<"3) QUIT game" <<std::endl;
        std::cout <<"> ";

        std::cin >>opt;

        std::cout <<"------------------------" <<std::endl;

        switch(opt) {
            case(1):
                std::cout <<hero;
                break;
            case(2):
                //fight the enemy and evaluate who won
                if(game(hero, enemy, fout) == 0)
                    std::cout <<std::endl <<"You were slain!" <<std::endl;
                else
                    std::cout <<std::endl <<"You killed " <<enemy.getName() 
                    <<"! You win!" <<std::endl;

                //return to main after result
                return 1;
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

    //read player and enemy data
    Enemy enemy("Ala_rau");
    Hero hero;
    std::cin >>hero;
    hero.set_stats();
    enemy.set_stats();

    //open file for logging
    std::ofstream fout;
    fout.open("game_logs.out");

    //main menu
    start(hero, enemy, fout);

    //close logging
    fout.close();

    return 0;
}