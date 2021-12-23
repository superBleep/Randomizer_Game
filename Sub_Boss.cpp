#include "Sub_Boss.hpp"

easyBoss::easyBoss(std::string name) : Boss("Small Bingus") {
    set_stats();

    if(HP == -1 || Defence == -1 || Parry == -1 || name == "")
        throw StatsException();
}

void easyBoss::set_stats(){
    HP = 50;
    Defence = 35;
    Parry = 5;
}

medBoss::medBoss(std::string name) : Boss("Average Bingus") {
    set_stats();

    if(HP == -1 || Defence == -1 || Parry == -1 || name == "")
        throw StatsException();
}

void medBoss::set_stats(){
    HP = 100;
    Defence = 50;
    Parry = 10;

    if(HP == -1 || Defence == -1 || Parry == -1 || name == "")
        throw StatsException();
}

hardBoss::hardBoss(std::string name) : Boss("Huge Bingus") {
    set_stats();

    if(HP == -1 || Defence == -1 || Parry == -1 || name == "")
        throw StatsException();
}

void hardBoss::set_stats(){
    HP = 150;
    Defence = 65;
    Parry = 15;

    if(HP == -1 || Defence == -1 || Parry == -1 || name == "")
        throw StatsException();
}