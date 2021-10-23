class Weapon
{
        int dmg;

        const int MIN_WEP_DMG = 10;
        const int MAX_WEP_DMG = 50;
    public:
        //constructor and initializer list
        Weapon(){
            dmg = (rand() % (MAX_WEP_DMG + 1 - MIN_WEP_DMG)) + MIN_WEP_DMG;
        }

        //copy constructor
        Weapon(const Weapon &w){
            dmg = w.dmg;
        }

        //asingment operator
        Weapon &operator=(const Weapon &w){
            this->dmg = w.dmg;
            return *this;
        }

        //destructor
        ~Weapon() {}

        int getDmg(){
            return dmg;
        }

        //operator<<
        friend std::ostream &operator<<(std::ostream &os, Weapon& w){
            os <<"Weapon damage: " <<w.dmg;
        }
};