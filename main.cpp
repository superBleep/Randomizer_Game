#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Player.h"

int game(Player &hero, Player &enemy, std::ostream &fout){
    int opt;
    while(1){
        std::cout <<"------------------------" <<std::endl;
        std::cout <<hero.getName() <<" is fighting " <<enemy.getName() <<"!" <<std::endl;
        std::cout <<"1) Check STATS" <<std::endl;
        std::cout <<"2) ATTACK "<<enemy.getName() <<std::endl;
        std::cout <<"3) PARRY incoming attack" <<std::endl;
        std::cout <<"> ";

        std::cin >>opt;

        std::cout <<"------------------------" <<std::endl;

        int max_st = hero.getStamina();

        switch(opt) {
            case(1):
                std::cout <<hero;
                break;
            case(2):
                if(hero.getStamina() > 0){
                    hero.attackEnemy(enemy, fout);
                    fout <<"------------------------" <<std::endl;
                    hero.setStamina(hero.getStamina() - 10);
                }
                else{
                    std::cout <<"You ran out of stamina! Wait for it to regenerate..." <<std::endl;
                }
                if(enemy.getHP() <= 0)
                    return 1;
                break;
            case(3):
                hero.parryAttack("buff");
                enemy.attackEnemy(hero, fout);
                fout <<"------------------------" <<std::endl;
                hero.parryAttack("debuff");
                if(hero.getStamina() <= max_st)
                    hero.setStamina(hero.getStamina() + 10);
                if(hero.getHP() <= 0)
                    return 0;
                break;
        }
    }
}

int start(Player &hero, Player &enemy, std::ostream &fout){
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
                if(game(hero, enemy, fout) == 0)
                    std::cout <<std::endl <<"You were slain!" <<std::endl;
                else
                    std::cout <<std::endl <<"You killed " <<enemy.getName() 
                    <<"! You win!" <<std::endl;
                return 1;
                break;
            case(3):
                std::cout <<"You quit the game. :(" <<std::endl;
                return 1;
        }
    }
}

int main(){
    //time seed for random number generator
    srand(time(NULL));

    Player hero, enemy("Badguy", "Type_2");
    std::cin >>hero;

    //open file for logging
    std::ofstream fout;
    fout.open("game_logs.out");

    start(hero, enemy, fout);

    //close logging
    fout.close();

    return 0;
}