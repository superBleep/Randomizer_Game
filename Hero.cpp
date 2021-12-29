#include "Hero.hpp"
#include "Sub_Hero.hpp"

//input function
void Hero::input(std::istream &is){
    std::cout <<"##### Randomizer! #####" <<std::endl;
    std::cout <<"Choose a NAME for your hero:" <<std::endl;
    std::cout <<"> ";

    is >>name;

    std::cout <<std::endl <<"Choose a TYPE for your hero:" <<std::endl;
    std::cout <<"Basic -> Base Stats: HP = 100 Stamina = 30 Defence = 50 Parry = 15" <<std::endl;
    std::cout <<"Light -> Base Stats: HP = 50 Stamina = 60 Defence = 35 Parry = 30" <<std::endl;
    std::cout <<"Heavy -> Base Stats: HP = 200 Stamina = 10 Defence = 65 Parry = 5" <<std::endl;
    std::cout <<"> ";

    is >>type;

    //throw exception if wrong type is given
    if(type != "Basic" && type != "basic" && type != "Light" 
    && type != "light" && type != "Heavy" && type != "heavy")
        throw TypeException();
}

//function used to create hero object based on input
std::shared_ptr<Hero> Hero::create() {
    std::shared_ptr<Hero> e;
    e = std::make_shared<Hero>("name", "type");
    std::cin >> *e;

    if(e->type == "basic" || e->type == "Basic")
        e = std::make_shared<basicHero>(e->name, e->type);
    if(e->type == "light" || e->type == "Light")
        e = std::make_shared<lightHero>(e->name, e->type);
    if(e->type == "heavy" || e->type == "Heavy")
        e = std::make_shared<heavyHero>(e->name, e->type);

    e->set_stats();
    return e;
}

//operator>> and initializer list
std::istream &operator>>(std::istream &is, Hero &h){
    h.input(is);

    return is;
}

//operator<<
std::ostream &operator<<(std::ostream &os, const Hero &h){
    os <<"Name: " <<h.name <<std::endl
    <<"Type: " <<h.type <<std::endl
    <<"HP: " <<h.HP <<std::endl
    <<"Stamina: " <<h.Stamina <<std::endl
    <<"Defence: " <<h.Defence <<std::endl
    <<"Parry: " <<h.Parry <<std::endl
    <<h.weapon <<std::endl
    <<std::endl <<"Armor:" <<std::endl
    <<h.armor <<std::endl
    <<"Potions:" <<std::endl
    <<"Small potions: " <<h.potions[0] <<std::endl
    <<"Big potions: " <<h.potions[1] <<std::endl;

    return os;
}

//healing functions
void Hero::give_potion(std::string potion_type){
    if(potion_type == "small_hp")
        potions[0]++;
    if(potion_type == "big_hp")
        potions[1]++;
}

int Hero::potion_choice(int potion_type){
    int HP_copy;
    int potion_name;
    if(potion_type == 0) potion_name = small_hp;
    if(potion_type == 1) potion_name = big_hp;

    if(potions[potion_type] == 0)
        return -2; //not enough potions
    else{
        potions[potion_type]--;
        if(HP + potion_name >= max_hp){
            HP_copy = HP;
            HP = max_hp;
            return max_hp - HP_copy; //return how much of the potion is used
        }
        else{
            HP += potion_name;
            return potion_name; //return potion
        }
    }
}

int Hero::heal(int potion_type){
    if(HP == max_hp)
        return -1; //HP already at max
    else
        return potion_choice(potion_type - 1);
    
    return 0;
}
