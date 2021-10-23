#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Player.h"

int game(Player &hero){
    int opt;
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

    //------testing
    Player hero, enemy("Bingo", "Type_2");
    std::cin >>hero;

    std::cout <<hero <<std::endl <<enemy <<std::endl;
    hero.attackEnemy(enemy);
    std::cout <<enemy;
    //------testing

    return 0;
}