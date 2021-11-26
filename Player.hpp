#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

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
        Weapon weapon;
        Armor armor;
        std::string name;
        int HP;
        int Defence;
        int Parry;

        const static int HEAD_CHANCE = 15;
        const static int BODY_CHANCE = 75;

        //set stats
        virtual void set_stats() = 0;
    public:
        //default constructor
        Player() {}

        //copy constructor
        Player(const Player &p);

        ///asingment operator
        Player &operator=(const Player &p){
            this->weapon = p.weapon;
            this->name = p.name;

            this->HP = p.HP;
            this->Defence = p.Defence;
            
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

//copy constructor
Player::Player(const Player &p){
    this->weapon = p.weapon;
    this->name = p.name;
    HP = p.HP;
    Defence = p.Defence;
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


///HERO (PLAYER SUBCLASS)
class Hero : public Player {
        int Stamina;
        std::string type;

        std::vector<int> potions = {0, 0};
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


///ENEMY (PLAYER SUBCLASS)
class Enemy : public Player {
        const int MAX_ENEMY_HP = 200;
        const int MIN_ENEMY_HP = 50;
        const int MAX_ENEMY_DEFENCE = 65;
        const int MIN_ENEMY_DEFENCE = 35;
        const int MAX_ENEMY_PARRY = 30;
        const int MIN_ENEMY_PARRY = 5;

        void set_stats();
    public:
        //constructor
        Enemy(const std::string& name);

        //operator<<
        friend std::ostream &operator<<(std::ostream &os, const Enemy &e);
};

//constructor
Enemy::Enemy(const std::string& name){
    set_stats();
    this->name = name;
}

//set stats randomly
void Enemy::set_stats(){
    HP = (rand() % (MAX_ENEMY_HP + 1 - MIN_ENEMY_HP)) + MIN_ENEMY_HP;
    Defence = (rand() % (MAX_ENEMY_DEFENCE + 1 - MIN_ENEMY_DEFENCE)) + MIN_ENEMY_DEFENCE;
    Parry = (rand() % (MAX_ENEMY_PARRY + 1 - MIN_ENEMY_PARRY)) + MAX_ENEMY_PARRY;
}

//operator<<
std::ostream &operator<<(std::ostream &os, const Enemy &e){
    os <<"Name: " <<e.name <<std::endl
    <<"HP: " <<e.HP <<std::endl
    <<"Defence: " <<e.Defence <<std::endl
    <<"Parry: " <<e.Parry <<std::endl
    <<e.weapon <<std::endl
    <<std::endl <<"Armor:" <<std::endl
    <<e.armor;

    return os;
}
