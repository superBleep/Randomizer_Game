#ifndef HERO_HPP
#define HERO_HPP

#include <array>
#include <memory>

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

        //function to choose potion to be given
        int potion_choice(int potion_type);

        //constructor w/ default values for exceptions
        Hero(std::string name, std::string type) : type(type) {
            this->name = name;
            Stamina = -1;
            small_hp = -1;
            big_hp = -1;
            max_hp = -1;
        }
    public:
        //function to create a smart pointer object
        static std::shared_ptr<Hero> create();

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
        
        //stat-setting function
        virtual void set_stats() = 0;

        //healing functions
        void give_potion(std::string potion_type);
        int heal(int potion_type);

        //function to show hero type
        virtual void show_type() = 0;
};

#endif