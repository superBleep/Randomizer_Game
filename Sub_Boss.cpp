#include "Sub_Boss.hpp"

void easyBoss::set_stats(){
    HP = 50;
    Defence = 35;
    Parry = 5;
}

void easyBoss::give_potion(Hero &hero){
    hero.give_potion("small_hp");
}

void medBoss::set_stats(){
    HP = 100;
    Defence = 50;
    Parry = 10;
}

void medBoss::give_potion(Hero &hero){
    hero.give_potion("big_hp");
}

void hardBoss::set_stats(){
    HP = 150;
    Defence = 65;
    Parry = 15;
}

void hardBoss::give_potion(Hero &hero){
    hero.give_potion("small_hp");
    hero.give_potion("big_hp");
}
