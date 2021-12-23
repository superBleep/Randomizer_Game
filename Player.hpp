#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <memory>

#include "Weapon.hpp"
#include "Armor.hpp"
#include "exceptions.hpp"

///PLAYER (ABSTRACT CLASS)
class Player {
    private:
        //attack head function
        void attackEnemyHead(Player &enemy, int formula, std::ostream &fout);

        //attack body function
        void attackEnemyBody(Player &enemy, int formula, std::ostream &fout);

        //attack legs function
        void attackEnemyLegs(Player &enemy, int formula, std::ostream &fout);
    protected:
        Weapon<> weapon;
        Armor<> armor;
        
        std::string name;
        
        int HP;
        int Defence;
        int Parry;

        const static int HEAD_CHANCE = 15;
        const static int BODY_CHANCE = 75;

        //set stats
        virtual void set_stats() = 0;
    public:
        //constructor w/ default values for exceptions
        Player(int HP = -1, int Defence = -1, int Parry = -1) : HP(HP), Defence(Defence), Parry(Parry) {}

        Player(std::string name){
            this->name = name;
        }
        
        //copy constructor
        Player(const Player &p);

        ///assingment operator
        virtual Player &operator=(const Player &p){
            this->weapon = p.weapon;
            this->armor = p.armor;
            this->name = p.name;

            this->HP = p.HP;
            this->Defence = p.Defence;
            this->Parry = p.Parry;

            return *this;
        }

        //destructor
        virtual ~Player() {}

        //getters and setters
        std::string getName(){
            return this->name;
        }
        int getHP(){
            return this->HP;
        }

        //attack function
        void attackEnemy(Player &enemy, std::ostream &fout);

        //parry function
        void parryAttack(std::string state);
};

#endif