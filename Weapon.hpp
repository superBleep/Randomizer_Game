#ifndef WEAPON_HPP
#define WEAPON_HPP

template <int Min_Wep_Dmg = 10, int Max_Wep_Dmg = 50>
class Weapon
{
        int dmg;

        const static int MIN_WEP_DMG = Min_Wep_Dmg;
        const static int MAX_WEP_DMG = Max_Wep_Dmg;
    public:
        //constructor and initializer list
        Weapon(){
            dmg = (rand() % (MAX_WEP_DMG + 1 - MIN_WEP_DMG)) + MIN_WEP_DMG;
        }

        //copy constructor
        Weapon(const Weapon<Min_Wep_Dmg, Max_Wep_Dmg> &w){
            dmg = w.dmg;
        }

        //asingment operator
        Weapon &operator=(const Weapon<Min_Wep_Dmg, Max_Wep_Dmg> &w){
            this->dmg = w.dmg;
            return *this;
        }

        //destructor
        ~Weapon() {}

        int getDmg(){
            return dmg;
        }

        //operator<<
        friend std::ostream &operator<<(std::ostream &os, const Weapon<Min_Wep_Dmg, Max_Wep_Dmg>& w){
            os <<"Weapon damage: " <<w.dmg;
            return os;
        }
};

#endif