#define MIN_WEP_DMG 10
#define MAX_WEP_DMG 50

class Weapon
{
        int *dmg;
    public:
        //constructor and initializer list
        Weapon(){
            dmg = new int;
            *dmg = (rand() % (MAX_WEP_DMG + 1 - MIN_WEP_DMG)) + MIN_WEP_DMG;
        }

        //copy constructor
        Weapon(const Weapon &w){
            *dmg = *w.dmg;
        }

        //asingment operator
        Weapon &operator=(const Weapon &w){
            *dmg = *w.dmg;
            return *this;
        }

        //destructor
        ~Weapon() {
            delete dmg;
        }

        int getDmg(){
            return *dmg;
        }

        //operator<<
        friend std::ostream &operator<<(std::ostream &os, Weapon& w){
            os <<"Weapon damage: " <<*w.dmg;
        }
};