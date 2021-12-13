#ifndef SUB_HERO_HPP
#define SUB_HERO_HPP

#include "Hero.hpp"

class basicHero : public Hero {
    public:
        basicHero(std::string name, std::string type);
        void set_stats();
};

class lightHero : public Hero {
    public:
        lightHero(std::string name, std::string type);
        void set_stats();
};

class heavyHero : public Hero {
    public:
        heavyHero(std::string name, std::string type);
        void set_stats();
};

#endif