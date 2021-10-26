#include "Weapon.h"
#include "Armor.h"

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
        void attackEnemyHead(Player &enemy, int high, int formula, std::ostream &fout);

        //attack body function
        void attackEnemyBody(Player &enemy, int high, int formula, std::ostream &fout);

        //attack legs function
        void attackEnemyLegs(Player &enemy, int high, int formula, std::ostream &fout);
};

//constructor
Player::Player(std::string name, std::string type) {
    this->name = name;
    this->type = type;
    if(type == "Type_1"){
        HP = 100;
        Stamina = 20;
        Defence = 63;
    }
    if(type == "Type_2"){
        HP = 200;
        Stamina = 40;
        Defence = 27;
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
    std::cout <<"##### Randomizer Game: C++ OOP Text-based RPG #####" <<std::endl;
    std::cout <<"Choose a NAME for your hero:" <<std::endl;
    std::cout <<"> ";

    is >>p.name;

    std::cout <<"Choose a TYPE for your hero:" <<std::endl;
    std::cout <<"Type_1 -> Base Stats: HP = 100 Stamina = 20 Defence = 63 Parry = 15" <<std::endl;
    std::cout <<"Type_2 -> Base Stats: HP = 200 Stamina = 40 Defence = 27 Parry = 20" <<std::endl;
    std::cout <<"> ";

    is >>p.type;

    if(p.type == "Type_1"){
        p.HP = 100;
        p.Stamina = 20;
        p.Defence = 63;
        p.Parry = 15;
    }
    if(p.type == "Type_2"){
        p.HP = 200;
        p.Stamina = 40;
        p.Defence = 27;
        p.Parry = 20;
    }

    return is;
}

//attack head function
void Player::attackEnemyHead(Player &enemy, int high, int formula, std::ostream &fout){
    //armor isn't broken
    if(enemy.armor.getHead() > 0){
        //logs - Head Armor
        fout <<enemy.getName() <<" hit in Head Armor for " <<formula
        <<" (" <<high % 100  <<"% out of " <<weapon.getDmg() <<")" <<std::endl;

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
        fout <<enemy.getName() <<" hit in HP (Armor broken) for " <<formula
        <<" (" <<high % 100  <<"% out of " <<weapon.getDmg() <<")" <<std::endl;

        std::cout <<"Head Armor broken! Additional "
        <<formula <<" damage to " <<enemy.getName() <<"'s HP." <<std::endl;

        //damage calculation
        enemy.HP -= formula - 1;
    }
}

//attack body function
void Player::attackEnemyBody(Player &enemy, int high, int formula, std::ostream &fout){
    //armor isn't broken
    if(enemy.armor.getBody() > 0){
        //logs - Body Armor
        fout <<enemy.getName() <<" hit in Body Armor for " <<formula
        <<" (" <<high % 100  <<"% out of " <<weapon.getDmg() <<")" <<std::endl;

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
        fout <<enemy.getName() <<" hit in HP (Armor broken) for " <<formula
        <<" (" <<high % 100  <<"% out of " <<weapon.getDmg() <<")" <<std::endl;

        std::cout <<"Body Armor broken! Additional "
        <<formula <<" damage to " <<enemy.getName() <<"'s HP." <<std::endl;

        //damage calculation
        enemy.HP -= formula - 1;
    }
}

//attack legs function
void Player::attackEnemyLegs(Player &enemy, int high, int formula, std::ostream &fout){
    //armor isn't broken
    if(enemy.armor.getLegs() > 0){
        //logs - Legs Armor
        fout <<enemy.getName() <<" hit in Legs Armor for " <<formula
        <<" (" <<high % 100  <<"% out of " <<weapon.getDmg() <<")" <<std::endl;

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
        fout <<enemy.getName() <<" hit in HP (Armor broken) for " <<formula
        <<" (" <<high % 100  <<"% out of " <<weapon.getDmg() <<")" <<std::endl;

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
    fout <<enemy.getName() <<" hit in HP for " <<low % 100 * weapon.getDmg() / 100
    <<" (" <<low % 100 <<"% out of " <<weapon.getDmg() <<")" <<std::endl;

    std::cout <<low % 100 * weapon.getDmg() / 100 <<" dmg dealt to " <<enemy.getName()
    <<"'s HP!" <<std::endl;

    //damage calculation
    enemy.HP -= low % 100 * weapon.getDmg() / 100;

    ///-----------------Armor---------------
    int formula = high % 100 * weapon.getDmg() / 100 + 1;

    //+1 to every scenario to fix division loss
    if(chance <= HEAD_CHANCE)
        enemy.attackEnemyHead(enemy, high, formula, fout);
    else if(chance <= BODY_CHANCE)
        enemy.attackEnemyBody(enemy, high, formula, fout);
    else
        enemy.attackEnemyLegs(enemy, high, formula, fout);
}

//parry function
void Player::parryAttack(std::string state){
    if(state == "buff")
        Defence += Defence * Parry / 100;
    if(state == "debuff")
        Defence -= Defence * Parry / 100;
}