#define MIN_AP 20
#define MAX_AP 100

class Armor
{
        int head;
        int body;
        int legs;
    public:
        //constructor and initializer list
        Armor(){
            head = (rand() % (MAX_AP + 1 - MIN_AP)) + MIN_AP;
            body = (rand() % (MAX_AP + 1 - MIN_AP)) + MIN_AP;
            legs = (rand() % (MAX_AP + 1 - MIN_AP)) + MIN_AP;
        }

        //copy constructor
        Armor(const Armor &a){
            head = a.head;
            body = a.body;
            legs = a.legs;
        }

        //asingment operator
        Armor &operator=(const Armor &a){
            head = a.head;
            body = a.body;
            legs = a.legs;
            return *this;
        }

        //destructor
        ~Armor() {}

        //getters and setters
        int getHead(){
            return head;
        }
        int getBody(){
            return body;
        }
        int getLegs(){
            return legs;
        }
        void setHead(int head){
            this->head = head;
        }
        void setBody(int body){
            this->body = body;
        }
        void setLegs(int legs){
            this->legs = legs;
        }

        //operator<<
        friend std::ostream &operator<<(std::ostream &os, Armor& w){
            os <<"Head: " <<w.head <<std::endl
            <<"Body: " <<w.body <<std::endl
            <<"Legs: " <<w.legs <<std::endl;

            return os;
        }
};