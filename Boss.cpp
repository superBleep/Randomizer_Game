#include "Sub_Boss.hpp"

//input function
void input(std::string &btype){
    std::cout <<std::endl
    <<"Choose the difficulty of the boss:" <<std::endl
    <<"Easy -> HP = 50 Defence = 35 Parry = 5" <<std::endl
    <<"Medium -> HP = 100 Defence = 50 Parry = 10" <<std::endl
    <<"Hard -> HP = 150 Defence = 65 Parry = 15" <<std::endl
    <<"> ";

    std::cin >>btype;

    if(btype != "Easy" && btype != "easy" && btype != "Medium" && btype != "medium"
    && btype != "Hard" && btype != "hard")
        throw TypeException();
}

//function to create a smart pointer object
std::shared_ptr<Boss> Boss::create() {
    std::string btype;
    
    std::shared_ptr<Boss> b;
    input(btype);

    if(btype == "easy" || btype == "Easy")
        b = std::make_shared<easyBoss>("Small Bingus");
    else if(btype == "medium" || btype == "Medium")
        b = std::make_shared<medBoss>("Average Bingus");
    else if(btype == "hard" || btype == "Hard")
        b = std::make_shared<hardBoss>("Huge Bingus");

    b->set_stats();

    //throw exception if stats have been incorrectly assigned
    if(b->HP == -1 || b->Defence == -1 || b->Parry == -1 || b->name == "")
        throw StatsException();

    return b;
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