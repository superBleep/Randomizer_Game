#ifndef HERO_CPP
#define HERO_CPP

#include "Hero.hpp"

//set stats based on type input
void Hero::set_stats(){
    if(type == "Basic" || type == "basic"){
        HP = 100;
        Stamina = 30;
        Defence = 50;
        Parry = 15;

        small_hp = 25;
        big_hp = 50;
    }
    if(type == "Light" || type == "light"){
        HP = 50;
        Stamina = 60;
        Defence = 35;
        Parry = 30;

        small_hp = 50 / 4;
        big_hp = 25;
    }
    if(type == "Heavy" || type == "heavy"){
        HP = 200;
        Stamina = 10;
        Defence = 65;
        Parry = 5;

        small_hp = 50;
        big_hp = 100;
    }
}

//operator>> and initializer list
std::istream &operator>>(std::istream &is, Hero &h){
    std::cout <<"##### Randomizer! #####" <<std::endl;
    std::cout <<"Choose a NAME for your hero:" <<std::endl;
    std::cout <<"> ";

    is >>h.name;

    std::cout <<std::endl <<"Choose a TYPE for your hero:" <<std::endl;
    std::cout <<"Basic -> Base Stats: HP = 100 Stamina = 30 Defence = 50 Parry = 15" <<std::endl;
    std::cout <<"Light -> Base Stats: HP = 50 Stamina = 60 Defence = 35 Parry = 30" <<std::endl;
    std::cout <<"Heavy -> Base Stats: HP = 200 Stamina = 10 Defence = 65 Parry = 5" <<std::endl;
    std::cout <<"> ";

    is >>h.type;
    if(h.type != "Basic" && h.type != "basic" && h.type != "Light" 
    && h.type != "light" && h.type != "Heavy" && h.type != "heavy")
        throw heroTypeException();

    h.set_stats();

    return is;
}

//operator<<
std::ostream &operator<<(std::ostream &os, const Hero &h){
    os <<"Name: " <<h.name <<std::endl
    <<"Type: " <<h.type <<std::endl
    <<"HP: " <<h.HP <<std::endl
    <<"Stamina: " <<h.Stamina <<std::endl
    <<"Defence: " <<h.Defence <<std::endl
    <<"Parry: " <<h.Parry <<std::endl
    <<h.weapon <<std::endl
    <<std::endl <<"Armor:" <<std::endl
    <<h.armor <<std::endl
    <<"Potions:" <<std::endl
    <<"Small potions: " <<h.potions[0] <<std::endl
    <<"Big potions: " <<h.potions[1] <<std::endl;

    return os;
}

//healing functions
void Hero::give_potion(std::string potion_type){
    if(potion_type == "small_hp")
        potions[0]++;
    if(potion_type == "big_hp")
        potions[1]++;
}

int Hero::heal(std::string potion_type, int value){
    if(potion_type == "small_hp"){
        //returns healed value if hero is healed successfully,
        //0 if we ran out of potions of this type
        if(potions[0] != 0){
            HP += value;
            potions[0]--;
            return value;
        }
        else
            return 0;
    }
    if(potion_type == "big_hp"){
        if(potions[1] != 0){
            HP += value;
            potions[1]--;
            return value;
        }
        else
            return 0;
    }
    return 0;
}

#endif