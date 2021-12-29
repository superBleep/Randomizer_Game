#ifndef SUB_BOSS_HPP
#define SUB_BOSS_HPP

#include "Boss.hpp"

class easyBoss : public Boss {
    private:
        void set_stats() override;

        void output(std::ostream &os) override;
    public:
        easyBoss(std::string name);
};

class medBoss : public Boss {
    private:
        void set_stats() override;

        void output(std::ostream &os) override;
    public:
        medBoss(std::string name);
};

class hardBoss : public Boss {
    private:
        void set_stats() override;

        void output(std::ostream &os) override;
    public:
        hardBoss(std::string name);
};

#endif
