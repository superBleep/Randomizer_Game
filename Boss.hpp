#ifndef BOSS_HPP
#define BOSS_HPP

#include "Player.hpp"

class Boss : public Player {
    protected:
        std::string btype;

        void input(std::istream &is);
    public:
        static std::shared_ptr<Boss> create();

        Boss(std::string name){
            this->name = name;
        }

        virtual void set_stats() {};

        friend std::istream &operator>>(std::istream &is, Boss &b);

        friend std::ostream &operator<<(std::ostream &os, const Boss &b);
};

#endif