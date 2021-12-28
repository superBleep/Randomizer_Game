#include "Sub_Boss.hpp"

//input function
void Boss::input(std::istream &is){
    std::cout <<std::endl
    <<"Choose the difficulty of the boss:" <<std::endl
    <<"Easy -> Weapon damage = 15, Armor up to = 50" <<std::endl
    <<"Medium -> Weapon damage = 30, Armor up to = 70" <<std::endl
    <<"Hard -> Weapon damage = 50, Armor up to = 100" <<std::endl
    <<"> ";

    is >>btype;

    if(btype != "Easy" && btype != "easy" && btype != "Medium" && btype != "medium"
    && btype != "Hard" && btype != "hard")
        throw TypeException();
}

//function to create a smart pointer object
std::shared_ptr<Boss> Boss::create() {
    std::shared_ptr<Boss> b;
    b = std::make_shared<Boss>("name");
    std::cin >> *b;

    if(b->btype == "easy" || b->btype == "Easy")
        b = std::make_shared<easyBoss>(b->name);
    if(b->btype == "medium" || b->btype == "Medium")
        b = std::make_shared<medBoss>(b->name);
    if(b->btype == "hard" || b->btype == "Hard")
        b = std::make_shared<hardBoss>(b->name);

    return b;
}

//input operator
std::istream &operator>>(std::istream &is, Boss &b){
    b.input(is);

    return is;
}

//output function
void Boss::output(std::ostream &os){
    os <<"Name: " <<name <<std::endl
    <<"HP: " <<HP <<std::endl
    <<"Defence: " <<Defence <<std::endl
    <<"Parry: " <<Parry <<std::endl
    <<weapon <<std::endl
    <<std::endl <<"Armor:" <<std::endl
    <<armor;
}

//output operator
std::ostream &operator<<(std::ostream &os, Boss &b){
    b.output(os);
    return os;
}