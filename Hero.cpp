#include "Hero.hpp"
#include "Sub_Hero.hpp"

//input function
void input(std::string &name, std::string &type){
    std::cout <<"##### Randomizer! #####" <<std::endl;
    std::cout <<"Choose a NAME for your hero:" <<std::endl;
    std::cout <<"> ";

    std::cin >>name;

    std::cout <<std::endl <<"Choose a TYPE for your hero:" <<std::endl;
    std::cout <<"Basic -> Base Stats: HP = 100 Stamina = 30 Defence = 50 Parry = 15" <<std::endl;
    std::cout <<"Light -> Base Stats: HP = 50 Stamina = 60 Defence = 35 Parry = 30" <<std::endl;
    std::cout <<"Heavy -> Base Stats: HP = 200 Stamina = 10 Defence = 65 Parry = 5" <<std::endl;
    std::cout <<"> ";

    std::cin >>type;

    //throw exception if wrong type is given
    if(type != "Basic" && type != "basic" && type != "Light" 
    && type != "light" && type != "Heavy" && type != "heavy")
        throw TypeException();
}

//function used to create hero object based on input
std::shared_ptr<Hero> Hero::create() {
    std::string name, type;
    
    std::shared_ptr<Hero> e;
    input(name, type);

    if(type == "basic" || type == "Basic")
        e = std::make_shared<basicHero>(name, type);
    else if(type == "light" || type == "Light")
        e = std::make_shared<lightHero>(name, type);
    else if(type == "heavy" || type == "Heavy")
        e = std::make_shared<heavyHero>(name, type);

    e->set_stats();

    //throw exception if stats have been incorrectly assigned
    if(e->HP == -1 || e->Defence == -1 || e->Parry == -1 || e->Stamina == -1 || e->name == "" || e->type == "")
        throw StatsException();

    return e;
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
    int potion_hp;
    if(potion_type == 0) potion_hp = small_hp;
    if(potion_type == 1) potion_hp = big_hp;

    if(potions[potion_type] == 0)
        return -2; //not enough potions
    else{
        potions[potion_type]--;
        if(HP + potion_hp >= max_hp){
            HP_copy = HP;
            HP = max_hp;
            return max_hp - HP_copy; //return how much of the potion is used
        }
        else{
            HP += potion_hp;
            return potion_hp; //return potion
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
