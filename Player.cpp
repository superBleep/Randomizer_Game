#include "Player.hpp"

//copy constructor
Player::Player(const Player &p){
    this->weapon = p.weapon;
    this->name = p.name;
    HP = p.HP;
    Defence = p.Defence;
}

//attack head function
void Player::attackEnemyHead(Player &enemy, int formula, std::ostream &fout){
    //armor isn't broken
    if(enemy.armor.getHead() > 0){
        //logs - Head Armor
        fout <<enemy.getName() <<" hit in Head Armor for " <<formula <<std::endl;

        std::cout <<"(" <<formula <<" absorbed by " <<enemy.getName() <<"'s Head Armor)" <<std::endl;

        //damage calculation
        if(formula >= enemy.armor.getHead())
            enemy.armor.setHead(0);
        else
            enemy.armor.setHead(enemy.armor.getHead() - formula);
    }
    //armor is broken
    else{
        //logs - Broken Head Armor
        fout <<enemy.getName() <<" hit in HP (Armor broken) for " <<formula <<std::endl;

        std::cout <<"Head Armor broken! Additional "
        <<formula <<" damage to " <<enemy.getName() <<"'s HP." <<std::endl;

        //damage calculation
        enemy.HP -= formula - 1;
    }
}

//attack body function
void Player::attackEnemyBody(Player &enemy, int formula, std::ostream &fout){
    //armor isn't broken
    if(enemy.armor.getBody() > 0){
        //logs - Body Armor
        fout <<enemy.getName() <<" hit in Body Armor for " <<formula <<std::endl;

        std::cout <<"(" <<formula <<" absorbed by " <<enemy.getName() <<"'s Body Armor)" <<std::endl;

        //damage calculation
        if(formula >= enemy.armor.getBody())
            enemy.armor.setBody(0);
        else
            enemy.armor.setBody(enemy.armor.getBody() - formula);
    }
    //armor is broken
    else{
        //logs - Broken Body Armor
        fout <<enemy.getName() <<" hit in HP (Armor broken) for " <<formula <<std::endl;

        std::cout <<"Body Armor broken! Additional "
        <<formula <<" damage to " <<enemy.getName() <<"'s HP." <<std::endl;

        //damage calculation
        enemy.HP -= formula - 1;
    }
}

//attack legs function
void Player::attackEnemyLegs(Player &enemy, int formula, std::ostream &fout){
    //armor isn't broken
    if(enemy.armor.getLegs() > 0){
        //logs - Legs Armor
        fout <<enemy.getName() <<" hit in Legs Armor for " <<formula <<std::endl;

        std::cout <<"(" <<formula <<" absorbed by " <<enemy.getName() <<"'s Legs Armor)" <<std::endl;

        //damage calculation
        if(formula >= enemy.armor.getLegs())
            enemy.armor.setLegs(0);
        else
            enemy.armor.setLegs(enemy.armor.getLegs() - formula);
    }
    //armor is broken
    else{
        //logs - Broken Legs Armor
        fout <<enemy.getName() <<" hit in HP (Armor broken) for " <<formula <<std::endl;

        std::cout <<"Armor broken! Additional "
        <<formula <<" damage to " <<enemy.getName() <<"'s HP." <<std::endl;

        //damage calculation
        enemy.HP -= formula - 1;
    }
}

//attack function
void Player::attackEnemy(Player &enemy, std::ostream &fout){
    //random hit accuracy interval
    int chance = rand() % 101;

    //logs - accuracy
    fout <<"Hit accuracy chance: " <<chance;
    if(chance <= HEAD_CHANCE)
        fout <<" => Head" <<std::endl;
    else if(chance <= BODY_CHANCE)
        fout <<" => Body" <<std::endl;
    else 
        fout <<" => Legs" <<std::endl;

    //the lower pct goes to HP, the rest goes to the armor, IF the armor isn't broken
    int low, high;
    if(Defence <= 50){
        low = Defence;
        high = (100 - Defence);
    }
    else{
        low = (100 - Defence);
        high = Defence;
    }

    ///-----------------HP-----------------
    //logs - HP
    fout <<enemy.getName() <<" hit in HP for " <<low % 100 * weapon.getDmg() / 100 <<std::endl;

    std::cout <<low % 100 * weapon.getDmg() / 100 <<" dmg dealt to " <<enemy.getName()
    <<"'s HP!" <<std::endl;

    //damage calculation
    enemy.HP -= low % 100 * weapon.getDmg() / 100;

    ///-----------------Armor---------------
    int formula = high % 100 * weapon.getDmg() / 100 + 1;

    //+1 to every scenario to fix division loss
    if(chance <= HEAD_CHANCE)
        enemy.attackEnemyHead(enemy, formula, fout);
    else if(chance <= BODY_CHANCE)
        enemy.attackEnemyBody(enemy, formula, fout);
    else
        enemy.attackEnemyLegs(enemy, formula, fout);
}

//parry function
void Player::parryAttack(std::string state){
    if(state == "buff")
        Defence += Defence * Parry / 100;
    if(state == "debuff")
        Defence -= Defence * Parry / 100;
}
