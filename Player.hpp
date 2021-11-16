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

//constructor
Player::Player(std::string name, std::string type) {
    this->name = name;
    this->type = type;
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

//copy constructor
Player::Player(const Player &p){
    this->weapon = p.weapon;
    this->name = p.name;
    this->type = p.type;
    HP = p.HP;
    Stamina = p.Stamina;
    Defence = p.Defence;
}

//operator<<
std::ostream &operator<<(std::ostream &os, Player &p){
    os <<"Name: " <<p.name <<std::endl
    <<"Type: " <<p.type <<std::endl
    <<"HP: " <<p.HP <<std::endl
    <<"Stamina: " <<p.Stamina <<std::endl
    <<"Defence: " <<p.Defence <<std::endl
    <<p.weapon <<std::endl
    <<std::endl <<"Armor:" <<std::endl
    <<p.armor;

    return os;
}

//operator>> and initializer list
std::istream &operator>>(std::istream &is, Player &p){
    std::cout <<"##### Randomizer! #####" <<std::endl;
    std::cout <<"Choose a NAME for your hero:" <<std::endl;
    std::cout <<"> ";

    is >>p.name;

    std::cout <<std::endl <<"Choose a TYPE for your hero:" <<std::endl;
    std::cout <<"Basic -> Base Stats: HP = 100 Stamina = 30 Defence = 50 Parry = 15" <<std::endl;
    std::cout <<"Light -> Base Stats: HP = 50 Stamina = 60 Defence = 35 Parry = 30" <<std::endl;
    std::cout <<"Heavy -> Base Stats: HP = 200 Stamina = 10 Defence = 65 Parry = 5" <<std::endl;
    std::cout <<"??? -> Base Stats: HP = ??? Stamina = ??? Defence = ??? Parry = ???" <<std::endl;
    std::cout <<"> ";

    is >>p.type;

    if(p.type == "Basic"){
        p.HP = 100;
        p.Stamina = 30;
        p.Defence = 50;
        p.Parry = 15;
    }
    if(p.type == "Light"){
        p.HP = 50;
        p.Stamina = 60;
        p.Defence = 35;
        p.Parry = 30;
    }
    if(p.type == "Heavy"){
        p.HP = 200;
        p.Stamina = 10;
        p.Defence = 65;
        p.Parry = 5;
    }
    if(p.type == "godmode"){
        p.HP = 20000;
        p.Stamina = 20000;
        p.Defence = 100;
        p.Parry = 0;
    }

    return is;
}

//attack head function
void Player::attackEnemyHead(Player &enemy, int formula, std::ostream &fout){
    //armor isn't broken
    if(enemy.armor.getHead() > 0){
        //logs - Head Armor
        fout <<enemy.getName() <<" hit in Head Armor for " <<formula <<std::endl;

        std::cout <<"(" <<formula <<" absorbed by " <<enemy.getName() <<"'s Head Armor)" <<std::endl;

        //damage calculation
        if(formula >= enemy.armor.getHead())
            enemy.armor.setHead(0);
        else
            enemy.armor.setHead(enemy.armor.getHead() - formula);
    }
    //armor is broken
    else{
        //logs - Broken Head Armor
        fout <<enemy.getName() <<" hit in HP (Armor broken) for " <<formula <<std::endl;

        std::cout <<"Head Armor broken! Additional "
        <<formula <<" damage to " <<enemy.getName() <<"'s HP." <<std::endl;

        //damage calculation
        enemy.HP -= formula - 1;
    }
}

//attack body function
void Player::attackEnemyBody(Player &enemy, int formula, std::ostream &fout){
    //armor isn't broken
    if(enemy.armor.getBody() > 0){
        //logs - Body Armor
        fout <<enemy.getName() <<" hit in Body Armor for " <<formula <<std::endl;

        std::cout <<"(" <<formula <<" absorbed by " <<enemy.getName() <<"'s Body Armor)" <<std::endl;

        //damage calculation
        if(formula >= enemy.armor.getBody())
            enemy.armor.setBody(0);
        else
            enemy.armor.setBody(enemy.armor.getBody() - formula);
    }
    //armor is broken
    else{
        //logs - Broken Body Armor
        fout <<enemy.getName() <<" hit in HP (Armor broken) for " <<formula <<std::endl;

        std::cout <<"Body Armor broken! Additional "
        <<formula <<" damage to " <<enemy.getName() <<"'s HP." <<std::endl;

        //damage calculation
        enemy.HP -= formula - 1;
    }
}

//attack legs function
void Player::attackEnemyLegs(Player &enemy, int formula, std::ostream &fout){
    //armor isn't broken
    if(enemy.armor.getLegs() > 0){
        //logs - Legs Armor
        fout <<enemy.getName() <<" hit in Legs Armor for " <<formula <<std::endl;

        std::cout <<"(" <<formula <<" absorbed by " <<enemy.getName() <<"'s Legs Armor)" <<std::endl;

        //damage calculation
        if(formula >= enemy.armor.getLegs())
            enemy.armor.setLegs(0);
        else
            enemy.armor.setLegs(enemy.armor.getLegs() - formula);
    }
    //armor is broken
    else{
        //logs - Broken Legs Armor
        fout <<enemy.getName() <<" hit in HP (Armor broken) for " <<formula <<std::endl;

        std::cout <<"Armor broken! Additional "
        <<formula <<" damage to " <<enemy.getName() <<"'s HP." <<std::endl;

        //damage calculation
        enemy.HP -= formula - 1;
    }
}

//attack function
void Player::attackEnemy(Player &enemy, std::ostream &fout){
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
    if(Defence <= 50){
        low = Defence;
        high = (100 - Defence);
    }
    else{
        low = (100 - Defence);
        high = Defence;
    }

    ///-----------------HP-----------------
    //logs - HP
    fout <<enemy.getName() <<" hit in HP for " <<low % 100 * weapon.getDmg() / 100 <<std::endl;

    std::cout <<low % 100 * weapon.getDmg() / 100 <<" dmg dealt to " <<enemy.getName()
    <<"'s HP!" <<std::endl;

    //damage calculation
    enemy.HP -= low % 100 * weapon.getDmg() / 100;

    ///-----------------Armor---------------
    int formula = high % 100 * weapon.getDmg() / 100 + 1;

    //+1 to every scenario to fix division loss
    if(chance <= HEAD_CHANCE)
        enemy.attackEnemyHead(enemy, formula, fout);
    else if(chance <= BODY_CHANCE)
        enemy.attackEnemyBody(enemy, formula, fout);
    else
        enemy.attackEnemyLegs(enemy, formula, fout);
}

//parry function
void Player::parryAttack(std::string state){
    if(state == "buff")
        Defence += Defence * Parry / 100;
    if(state == "debuff")
        Defence -= Defence * Parry / 100;
}