#ifndef SUB_BOSS_HPP
#define SUB_BOSS_HPP

#include "Boss.hpp"

class easyBoss : public Boss {
    private:
        void set_stats() override;
        void give_potion(Hero &hero) override;
    public:
        easyBoss(std::string name) {
            this->name = name;
        };
};

class medBoss : public Boss {
    private:
        void set_stats() override;
        void give_potion(Hero &hero) override;
    public:
        medBoss(std::string name) {
            this->name = name;
        };
};

class hardBoss : public Boss {
    private:
        void set_stats() override;
        void give_potion(Hero &hero) override;
    public:
        hardBoss(std::string name) {
            this->name = name;
        };
};

#endif
