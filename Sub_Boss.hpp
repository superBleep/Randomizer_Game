#ifndef SUB_BOSS_HPP
#define SUB_BOSS_HPP

#include "Boss.hpp"

class easyBoss : public Boss {
    private:
        Weapon<15, 15> weapon;
        Armor<50, 50> armor;

        void set_stats() override;

        void output(std::ostream &os) override;
    public:
        easyBoss(std::string name);

        Armor<50, 50> getArmor(){
            return armor;
        }
};

class medBoss : public Boss {
    private:
        Weapon<30, 30> weapon;
        Armor<70, 70> armor;

        void set_stats() override;

        void output(std::ostream &os) override;
    public:
        medBoss(std::string name);

        Armor<70, 70> getArmor(){
            return armor;
        }
};

class hardBoss : public Boss {
    private:
        Weapon<50, 50> weapon;
        Armor<100, 100> armor;

        void set_stats() override;

        void output(std::ostream &os) override;
    public:
        hardBoss(std::string name);

        Armor<100, 100> getArmor() {
            return armor;
        }
};

#endif
