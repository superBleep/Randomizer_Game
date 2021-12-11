#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Player.hpp"

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

#endif