#ifndef SUB_HERO_HPP
#define SUB_HERO_HPP

#include "Hero.hpp"

class basicHero : public Hero {
    private:
        void set_stats() override;
        void show_type() override;
    public:
        basicHero(std::string name, std::string type);
};

class lightHero : public Hero {
    private:
        void set_stats() override;
        void show_type() override;
    public:
        lightHero(std::string name, std::string type);
};

class heavyHero : public Hero {
    private:
        void set_stats() override;
        void show_type() override;
    public:
        heavyHero(std::string name, std::string type);
};

#endif