#ifndef BOSS_HPP
#define BOSS_HPP

#include "Player.hpp"

class Boss : public Player {
    protected:
        std::string btype;

        //input function used to read basic boss data (name and btype)
        void input(std::istream &is);

        //function to display boss data
        virtual void output(std::ostream &os);
    public:
        //function to create a smart pointer object
        static std::shared_ptr<Boss> create();

        //constructor
        Boss(std::string name){
            this->name = name;
        }

        //stat-setting functiong (empty, waiting to be implemented in subclass)
        virtual void set_stats() {};

        //input/output operators
        friend std::istream &operator>>(std::istream &is, Boss &b);
        friend std::ostream &operator<<(std::ostream &os, Boss &b);
};

#endif