#include "Sub_Hero.hpp"

basicHero::basicHero(std::string name, std::string type) : Hero(name, type) {
    set_stats();
    
    //throw exception if stats haven't been assigned correctly
    if(HP == -1 || Defence == -1 || Parry == -1 || Stamina == -1 || small_hp == -1 || big_hp == -1 || max_hp == -1 || name == "" || type == "")
        throw StatsException();
}

void basicHero::set_stats(){
    HP = 100;
    Stamina = 30;
    Defence = 50;
    Parry = 15;

    small_hp = 25;
    big_hp = 50;
    max_hp = 100;
}

void basicHero::show_type(){
    std::cout <<"------------------------" <<std::endl
    <<"With a set of average stats, " <<name <<" is a basic hero!" <<std::endl;
}

lightHero::lightHero(std::string name, std::string type) : Hero(name, type) {
    set_stats();
    this->name = name;
    this->type = type;

    if(HP == -1 || Defence == -1 || Parry == -1 || Stamina == -1 || name == "" || type == "")
        throw StatsException();
}

void lightHero::set_stats(){
    HP = 50;
    Stamina = 60;
    Defence = 35;
    Parry = 30;

    small_hp = 50 / 4;
    big_hp = 25;
    max_hp = 50;
}

void lightHero::show_type(){
    std::cout <<"------------------------" <<std::endl
    <<"Both fragile and agile, " <<name <<" is a light hero!" <<std::endl;
}

heavyHero::heavyHero(std::string name, std::string type) : Hero(name, type) {
    set_stats();
    this->name = name;
    this->type = type;

    if(HP == -1 || Defence == -1 || Parry == -1 || Stamina == -1 || name == "" || type == "")
        throw StatsException();
}

void heavyHero::set_stats() {
    HP = 200;
    Stamina = 10;
    Defence = 65;
    Parry = 5;

    small_hp = 50;
    big_hp = 100;
    max_hp = 200;
}

void heavyHero::show_type(){
    std::cout <<"------------------------" <<std::endl
    <<"Slow, yet built like a tank, " <<name <<" is a heavy hero!" <<std::endl;
}