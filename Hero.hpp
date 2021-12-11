#ifndef HERO_HPP
#define HERO_HPP

#include "Player.hpp"
#include "exceptions.hpp"

///HERO (PLAYER SUBCLASS)
class Hero : public Player {
        int Stamina;
        std::string type;

        int potions[2] = {0, 0};
        int small_hp, big_hp;
    public:
        //operator<<
        friend std::ostream &operator<<(std::ostream &os, const Hero &p);

        //operator>> and initializer list
        friend std::istream &operator>>(std::istream &is, Hero &p);

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

        //Stamina increase/decrease functions
        void increaseStamina(){
            this->Stamina += 10;
        }
        void decreaseStamina(){
            this->Stamina -= 10;
        }
        void set_stats();

        //healing functions
        void give_potion(std::string potion_type);
        int heal(std::string potion_type, int value);

};

#endif