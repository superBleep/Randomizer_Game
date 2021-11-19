#include "Player.hpp"

class Enemy : public Player {
        const int MAX_ENEMY_HP = 200;
        const int MIN_ENEMY_HP = 50;
        const int MAX_ENEMY_DEFENCE = 65;
        const int MIN_ENEMY_DEFENCE = 35;
        const int MAX_ENEMY_PARRY = 30;
        const int MIN_ENEMY_PARRY = 5;
    public:
        //constructor
        Enemy(const std::string name);

        //operator<<
        friend std::ostream &operator<<(std::ostream &os, Enemy &e);

        void set_stats();
};

//constructor
Enemy::Enemy(const std::string name){
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
std::ostream &operator<<(std::ostream &os, Enemy &e){
    os <<"Name: " <<e.name <<std::endl
    <<"HP: " <<e.HP <<std::endl
    <<"Defence: " <<e.Defence <<std::endl
    <<e.weapon <<std::endl
    <<std::endl <<"Armor:" <<std::endl
    <<e.armor;

    return os;
}
