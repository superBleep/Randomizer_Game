#ifndef HERO_HPP
#define HERO_HPP

#include <array>

#include "Player.hpp"
#include "exceptions.hpp"

///HERO (PLAYER SUBCLASS)
class Hero : public Player {
    protected:
        int Stamina;
        std::string type;

        std::array<int, 2> potions = { {0, 0} };
        int small_hp, big_hp;
        int max_hp;
    public:
        //constructor w/ default values for exceptions
        Hero(int Stamina = -1, int small_hp = -1, int big_hp = -1, int max_hp = -1) : Stamina(Stamina), small_hp(small_hp), big_hp(big_hp), max_hp(max_hp) {}

        //operator>> and initializer list
        friend std::istream &operator>>(std::istream &is, Hero &);

        //operator<<
        friend std::ostream &operator<<(std::ostream &os, const Hero &p);

        //assignment operator
        Hero &operator=(const Hero &h){
            this->weapon = h.weapon;
            this->armor = h.armor;
            this->name = h.name;
            this->type = h.type;

            this->HP = h.HP;
            this->Defence = h.Defence;
            this->Parry = h.Parry;
            
            this->Stamina = h.Stamina;
            for(unsigned int i = 0; i < potions.size(); i++)
                this->potions[i] = h.potions[i];
            this->small_hp = h.small_hp;
            this->big_hp = h.big_hp;
            this->max_hp = h.max_hp;

            return *this;
        }

        //getters and setters
        int getStamina(){
            return this->Stamina;
        }
        void setStamina(int Stamina){
            this->Stamina = Stamina;
        }
        int getSmallHP(){
            return this->small_hp;
        }
        int getBigHP(){
            return this->big_hp;
        }
        int getMaxHP(){
            return this->max_hp;
        }
        std::string getType(){
            return this->type;
        }

        //Stamina increase/decrease functions
        void increaseStamina(){
            this->Stamina += 10;
        }
        void decreaseStamina(){
            this->Stamina -= 10;
        }
        
        //stat-setting function (empty, waiting to be implemented in subclass)
        virtual void set_stats() {};

        //healing functions
        void give_potion(std::string potion_type);
        int heal(int potion_type);

};

#endif