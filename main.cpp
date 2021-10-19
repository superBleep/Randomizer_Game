///TODO: implement game
///TODO: fix segfault on using operator>>
///TODO: check if name, type inputs are correct

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "Player.h"

void intro(){
    std::cout <<"##### C++ OOP Text-based RPG #####" <<std::endl;
    std::cout <<"Choose a NAME and a TYPE for your hero:" <<std::endl;
    std::cout <<"Type_1 -> Base Stats: HP = 100 Stamina = 20 Defence = 63" <<std::endl;
    std::cout <<"Type_2 -> Base Stats: HP = 200 Stamina = 40 Defence = 27" <<std::endl;
    std::cout <<"> ";
}

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

    intro();
    Player hero("Hero", "Type_1"), enemy("Bingo", "Type_2");

    std::cout <<hero <<std::endl <<enemy <<std::endl;

    hero.attackEnemy(enemy);

    std::cout <<enemy;

    return 0;
}