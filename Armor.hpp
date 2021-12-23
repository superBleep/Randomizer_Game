#ifndef ARMOR_HPP
#define ARMOR_HPP

template <int Min_Ap = 20, int Max_Ap = 100>
class Armor
{
        int head;
        int body;
        int legs;

        const static int MIN_AP = Min_Ap;
        const static int MAX_AP = Max_Ap;
    public:
        //constructor and initializer list
        Armor(){
            head = (rand() % (MAX_AP + 1 - MIN_AP)) + MIN_AP;
            body = (rand() % (MAX_AP + 1 - MIN_AP)) + MIN_AP;
            legs = (rand() % (MAX_AP + 1 - MIN_AP)) + MIN_AP;
        }

        //copy constructor
        Armor(const Armor<Min_Ap, Max_Ap> &a){
            head = a.head;
            body = a.body;
            legs = a.legs;
        }

        //asingment operator
        Armor &operator=(const Armor<Min_Ap, Max_Ap> &a){
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
        friend std::ostream &operator<<(std::ostream &os, const Armor<Min_Ap, Max_Ap>& a){
            os <<"Head: " <<a.head <<std::endl
            <<"Body: " <<a.body <<std::endl
            <<"Legs: " <<a.legs <<std::endl;

            return os;
        }
};

#endif