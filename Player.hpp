#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "Weapon.hpp"
#include "Armor.hpp"

class Player {
        Weapon weapon;
        Armor armor;
        std::string name;
        std::string type;
        int HP;
        int Stamina;
        int Defence;
        int Parry;

        const int HEAD_CHANCE = 15;
        const int BODY_CHANCE = 75;
    public:
        //default constructor
        Player() {}

        //constructor
        Player(std::string name, std::string type);

        //copy constructor
        Player(const Player &p);

        ///asingment operator
        Player &operator=(const Player &p){
            this->weapon = p.weapon;
            this->name = p.name;
            this->type = p.type;

            this->HP = p.HP;
            this->Stamina = p.Stamina;
            this->Defence = p.Defence;
            
            return *this;
            //std::cout <<"Asingment operator";
        }

        //destructor
        ~Player() {}

        //getters and setters
        std::string getName(){
            return this->name;
        }
        int getHP(){
            return this->HP;
        }
        int getStamina(){
            return this->Stamina;
        }

        void setStamina(int Stamina){
            this->Stamina = Stamina;
        }

        //operator<<
        friend std::ostream &operator<<(std::ostream &os, Player &p);

        //operator>> and initializer list
        friend std::istream &operator>>(std::istream &is, Player &p);

        //attack function
        void attackEnemy(Player &enemy, std::ostream &fout);

        //parry function
        void parryAttack(std::string state);
    private:
        //attack head function
        void attackEnemyHead(Player &enemy, int formula, std::ostream &fout);

        //attack body function
        void attackEnemyBody(Player &enemy, int formula, std::ostream &fout);

        //attack legs function
        void attackEnemyLegs(Player &enemy, int formula, std::ostream &fout);
};

#endif