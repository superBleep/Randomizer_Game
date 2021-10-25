#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Player.h"

int game(Player &hero, Player &enemy){
    int opt;
    while(1){
        std::cout <<"------------------------" <<std::endl;
        std::cout <<hero.getName() <<" is fighting " <<enemy.getName() <<"!" <<std::endl;
        std::cout <<"1) Check STATS" <<std::endl;
        std::cout <<"2) ATTACK "<<enemy.getName() <<std::endl;
        std::cout <<"3) PARRY incoming attack" <<std::endl;
        std::cout <<"4) HEAL wounds" <<std::endl;
        std::cout <<"> ";

        std::cin >>opt;

        std::cout <<"------------------------" <<std::endl;

        switch(opt) {
            case(1):
                std::cout <<hero;
                break;
            case(2):
                hero.attackEnemy(enemy);
                if(enemy.getHP() <= 0)
                    return 1;
                break;
        }
    }
}

int start(Player &hero, Player &enemy){
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
                if(game(hero, enemy) == 0)
                    std::cout <<"You were slain!" <<std::endl;
                else
                    std::cout <<"You killed " <<enemy.getName() <<"!" <<std::endl;
                return 1;
                break;
            case(3):
                std::cout <<"Bye Bye!" <<std::endl;
                return 1;
        }
    }
}

int main(){
    //time seed for random number generator
    srand(time(NULL));

    Player hero, enemy("Badguy", "Type_2");
    std::cin >>hero;

    start(hero, enemy);

    return 0;
}