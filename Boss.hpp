#ifndef BOSS_HPP
#define BOSS_HPP

#include "Player.hpp"
#include "Hero.hpp"

class Boss : public Player {
    protected:
        std::string btype;

        //function to display boss data
        void output(std::ostream &os);

        //constructors
        Boss() {}

        Boss(std::string name){
            this->name = name;
        }
    public:
        //function to create a smart pointer object
        static std::shared_ptr<Boss> create();

        //stat-setting functiong
        virtual void set_stats() = 0;

        //output operator
        friend std::ostream &operator<<(std::ostream &os, Boss &b);

        //function to reward hero with potion after death
        virtual void give_potion(Hero &hero) = 0;
};

#endif