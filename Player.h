#define HEAD_CHANCE 15
#define BODY_CHANCE 75

#include "Weapon.h"
#include "Armor.h"

class Player {
        Weapon weapon;
        Armor armor;
        std::string name;
        std::string type;
        int *HP;
        int *Stamina;
        int *Defence;
    public:
        //default constructor
        Player() {}

        //constructor and initializer list
        Player(std::string name, std::string type);

        //copy constructor
        Player(const Player &p);

        ///asingment operator
        Player &operator=(const Player &p){
            this->weapon = p.weapon;
            this->name = p.name;
            this->type = p.type;

            HP = new int;
            *this->HP = *p.HP;

            Stamina = new int;
            *this->Stamina = *p.Stamina;

            Defence = new int;
            *this->Defence = *p.Defence;
            
            return *this;
            //std::cout <<"Asingment operator";
        }

        //destructor
        ~Player();

        //operator<<
        friend std::ostream &operator<<(std::ostream &os, Player &p);

        //operator>> and initializer list
        friend std::istream &operator>>(std::istream &is, Player &p);

        //attack function
        void attackEnemy(Player &enemy);
};

//constructor and initializer list
Player::Player(std::string name, std::string type) {
    this->name = name;
    this->type = type;
    if(type == "Type_1"){
        HP = new int; 
        *HP = 100;

        Stamina = new int;
        *Stamina = 20;

        Defence = new int;
        *Defence = 63;
    }
    if(type == "Type_2"){
        HP = new int; 
        *HP = 200;

        Stamina = new int;
        *Stamina = 40;

        Defence = new int;
        *Defence = 27;
    }
}

//copy constructor
Player::Player(const Player &p){
    this->weapon = p.weapon;
    this->name = p.name;
    this->type = p.type;
    HP = new int;
    *HP = *p.HP;

    Stamina = new int;
    *Stamina = *p.Stamina;

    Defence = new int;
    *Defence = *p.Defence;
}

//destructor
Player::~Player(){
    delete HP, Stamina, Defence;
}

//operator<<
std::ostream &operator<<(std::ostream &os, Player &p){
    os <<"Name: " <<p.name <<std::endl
    <<"Type: " <<p.type <<std::endl
    <<"HP: " <<*p.HP <<std::endl
    <<"Stamina: " <<*p.Stamina <<std::endl
    <<"Defence: " <<*p.Defence <<std::endl
    <<p.weapon <<std::endl
    <<std::endl <<"Armor:" <<std::endl
    <<p.armor;
    return os;
}

//operator>> and initializer list
std::istream &operator>>(std::istream &is, Player &p){
    std::cout <<"##### Randomizer Game: C++ OOP Text-based RPG #####" <<std::endl;
    std::cout <<"Choose a NAME for your hero:" <<std::endl;
    std::cout <<"> ";

    is >>p.name;

    std::cout <<"Choose a TYPE for your hero:" <<std::endl;
    std::cout <<"Type_1 -> Base Stats: HP = 100 Stamina = 20 Defence = 63" <<std::endl;
    std::cout <<"Type_2 -> Base Stats: HP = 200 Stamina = 40 Defence = 27" <<std::endl;
    std::cout <<"> ";

    is >>p.type;

    if(p.type == "Type_1"){
        p.HP = new int; 
        *p.HP = 100;

        p.Stamina = new int;
        *p.Stamina = 20;

        p.Defence = new int;
        *p.Defence = 63;
    }
    if(p.type == "Type_2"){
        p.HP = new int; 
        *p.HP = 200;

        p.Stamina = new int;
        *p.Stamina = 40;

        p.Defence = new int;
        *p.Defence = 27;
    }

    return is;
}

//attack function
void Player::attackEnemy(Player &enemy){
    //open file for logging
    std::ofstream fout;
    fout.open("game_logs.out");

    //random hit accuracy interval
    int chance = rand() % 101;

    //logs - accuracy
    fout <<"Hit accuracy chance: " <<chance;
    if(chance <= HEAD_CHANCE)
        fout <<" => Head" <<std::endl;
    else if(chance <= BODY_CHANCE)
        fout <<" => Body" <<std::endl;
    else 
        fout <<" => Legs" <<std::endl;

    //the lower pct goes to HP, the rest goes to the armor, IF the armor isn't broken
    int low, high;
    if(*Defence <= 50){
        low = *Defence;
        high = (100 - *Defence);
    }
    else{
        low = (100 - *Defence);
        high = *Defence;
    }

    ///-----------------HP-----------------
    //logs - HP
    fout <<"Enemy hit in HP for: " <<low % 100 <<"% out of "
    <<weapon.getDmg() <<" = " <<low % 100 * weapon.getDmg() / 100 <<std::endl
    <<"HP before: " <<*enemy.HP <<std::endl;

    //damage calculation
    *enemy.HP -= low % 100 * weapon.getDmg() / 100;

    //logs - HP
    fout <<"HP after: " <<*enemy.HP <<std::endl;

    ///-----------------Armor---------------
    int formula = high % 100 * weapon.getDmg() / 100 + 1;

    //+1 to every scenario to fix division loss
    if(chance <= HEAD_CHANCE){
        //armor isn't broken
        if(enemy.armor.getHead() > 0){
            //logs - Head Armor
            fout <<"Enemy hit in Head Armor for: " <<high % 100 <<"% out of "
            <<weapon.getDmg() <<" = " <<formula - 1 <<" (+ 1)" <<std::endl
            <<"Head Armor before: " <<enemy.armor.getHead() <<std::endl
            <<"Head Armor after: " <<enemy.armor.getHead() - formula <<std::endl;

            //damage calculation
            if(formula >= enemy.armor.getHead())
                enemy.armor.setHead(0);
            else
                enemy.armor.setHead(enemy.armor.getHead() - formula);
        }
        //armor is broken
        else{
            //logs - Broken Head Armor
            fout <<"Armor broken: enemy hit in HP for: " <<high % 100 <<"% out of "
            <<weapon.getDmg() <<" = " <<formula - 1 <<" (+ 1)" <<std::endl
            <<"HP before: " <<*enemy.HP <<std::endl;

            //damage calculation
            *enemy.HP -= formula - 1;

            //logs - Broken Head Armor
            fout <<"HP after: " <<*enemy.HP <<std::endl;
        }
    }
    else if(chance <= BODY_CHANCE){
        //armor isn't broken
        if(enemy.armor.getBody() > 0){
            //logs - Body Armor
            fout <<"Enemy hit in Body Armor for: " <<high % 100 <<"% out of "
            <<weapon.getDmg() <<" = " <<formula - 1 <<" (+ 1)" <<std::endl
            <<"Body Armor before: " <<enemy.armor.getBody() <<std::endl
            <<"Body Armor after: " <<enemy.armor.getBody() - formula <<std::endl;

            //damage calculation
            if(formula >= enemy.armor.getBody())
                enemy.armor.setBody(0);
            else
                enemy.armor.setBody(enemy.armor.getBody() - formula);
        }
        //armor is broken
        else{
            //logs - Broken Body Armor
            fout <<"Armor broken: enemy hit in HP for: " <<high % 100 <<"% out of "
            <<weapon.getDmg() <<" = " <<formula - 1 <<" (+ 1)" <<std::endl
            <<"HP before: " <<*enemy.HP <<std::endl;

            //damage calculation
            *enemy.HP -= formula - 1;

            //logs - Broken Body Armor
            fout <<"HP after: " <<*enemy.HP <<std::endl;
        }
    }
    else{
        //armor isn't broken
        if(enemy.armor.getLegs() > 0){
            //logs - Legs Armor
            fout <<"Enemy hit in Legs Armor for: " <<high % 100 <<"% out of "
            <<weapon.getDmg() <<" = " <<formula - 1 <<" (+ 1)" <<std::endl
            <<"Legs Armor before: " <<enemy.armor.getLegs() <<std::endl
            <<"Legs Armor after: " <<enemy.armor.getLegs() - formula <<std::endl;

            //damage calculation
            if(formula >= enemy.armor.getLegs())
                enemy.armor.setLegs(0);
            else
                enemy.armor.setLegs(enemy.armor.getLegs() - formula);
        }
        //armor is broken
        else{
            //logs - Broken Legs Armor
            fout <<"Armor broken: enemy hit in HP for: " <<high % 100 <<"% out of "
            <<weapon.getDmg() <<" = " <<formula - 1 <<" (+ 1)" <<std::endl
            <<"HP before: " <<*enemy.HP <<std::endl;

            //damage calculation
            *enemy.HP -= formula - 1;

            //logs - Broken Legs Armor
            fout <<"HP after: " <<*enemy.HP <<std::endl;
        }
    }
    
    //close logging
    fout.close();
}