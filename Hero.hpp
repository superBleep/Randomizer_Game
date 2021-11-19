#include "Player.hpp"

class Hero : public Player {
        int Stamina;
        std::string type;
    public:
        //operator<<
        friend std::ostream &operator<<(std::ostream &os, Hero &p);

        //operator>> and initializer list
        friend std::istream &operator>>(std::istream &is, Hero &p);

        //Stamina getter and setter
        int getStamina(){
            return this->Stamina;
        }
        void setStamina(int Stamina){
            this->Stamina = Stamina;
        }

        void set_stats();
};

//set stats based on type input
void Hero::set_stats(){
    if(type == "Basic"){
        HP = 100;
        Stamina = 30;
        Defence = 50;
        Parry = 15;
    }
    if(type == "Light"){
        HP = 50;
        Stamina = 60;
        Defence = 35;
        Parry = 30;
    }
    if(type == "Heavy"){
        HP = 200;
        Stamina = 10;
        Defence = 65;
        Parry = 5;
    }
    if(type == "godmode"){
        HP = 20000;
        Stamina = 20000;
        Defence = 100;
        Parry = 0;
    }
}

//operator<<
std::ostream &operator<<(std::ostream &os, Hero &h){
    os <<"Name: " <<h.name <<std::endl
    <<"Type: " <<h.type <<std::endl
    <<"HP: " <<h.HP <<std::endl
    <<"Stamina: " <<h.Stamina <<std::endl
    <<"Defence: " <<h.Defence <<std::endl
    <<h.weapon <<std::endl
    <<std::endl <<"Armor:" <<std::endl
    <<h.armor;

    return os;
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
    std::cout <<"??? -> Base Stats: HP = ??? Stamina = ??? Defence = ??? Parry = ???" <<std::endl;
    std::cout <<"> ";

    is >>h.type;

    if(h.type == "Basic"){
        h.HP = 100;
        h.Stamina = 30;
        h.Defence = 50;
        h.Parry = 15;
    }
    if(h.type == "Light"){
        h.HP = 50;
        h.Stamina = 60;
        h.Defence = 35;
        h.Parry = 30;
    }
    if(h.type == "Heavy"){
        h.HP = 200;
        h.Stamina = 10;
        h.Defence = 65;
        h.Parry = 5;
    }
    if(h.type == "godmode"){
        h.HP = 20000;
        h.Stamina = 20000;
        h.Defence = 100;
        h.Parry = 0;
    }

    return is;
}
