#include "Player.hpp"
#include "Sub_Hero.hpp"
#include "Enemy.hpp"
#include "Sub_Boss.hpp"
#include "Game.hpp"
#include <stack>

template <typename T>
int start(Hero &hero, std::stack< std::unique_ptr<Enemy> > &enemy_stack, T &boss, std::ostream &fout){
    int opt, result, init_stamina, boss_flag = 0;
    init_stamina = hero.getStamina();

    while(1){
        std::cout <<"------------------------" <<std::endl
        <<"Choose an option:" <<std::endl
        <<"1) Check STATS" <<std::endl
        <<"2) FIGHT enemies" <<std::endl
        <<"3) FIGHT boss" <<std::endl
        <<"4) QUIT game" <<std::endl
        <<"> ";

        std::cin >>opt;

        std::cout <<"------------------------" <<std::endl;

        switch(opt) {
            case(1):
                std::cout <<hero;
                break;
            case(2):
                //fight enemies from the stack until either the stack is empty or you die
                result = game<Enemy>(hero, *enemy_stack.top(), fout);
                if(result == 0){
                    std::cout <<std::endl <<"You were killed. Game over!" <<std::endl;
                    return 1;
                }
                else{
                    std::cout <<"------------------------";
                    std::cout <<std::endl <<"You killed " <<enemy_stack.top()->getName() <<std::endl;

                    hero.setStamina(init_stamina);
                    enemy_stack.pop();

                    //if you killed all the enemies, return to main
                    if(enemy_stack.empty() == 1){
                        std::cout <<std::endl <<"You killed all the enemies! You win!" <<std::endl;
                        return 1;
                    }
                }
                break;
            case(3):
                if(boss_flag == 0) {
                    result = game<decltype(boss)>(hero, boss, fout);
                    if(result == 0){
                        std::cout <<std::endl <<"You were killed. Game over!" <<std::endl;
                        return 1;
                    }
                    else{
                        std::cout <<"------------------------";
                        std::cout <<std::endl <<"You killed " <<boss.getName() <<std::endl;

                        boss_flag = 1;
                        hero.setStamina(init_stamina);
                    }
                    break;
                }
                else {
                    std::cout <<"You already defeated the boss!" <<std::endl;
                    break;
                }
            case(4):
                std::cout <<"You quit the game. :(" <<std::endl;

                //return to main after result
                return 1;
        }
    }
}

template <> int start(Hero &hero, std::stack< std::unique_ptr<Enemy> > &enemy_stack, easyBoss &boss, std::ostream &fout);

int main(){
    //time seed for random number generator
    srand(time(NULL));

    //enemies declaration
    std::stack< std::unique_ptr<Enemy> > enemy_stack;
    enemy_stack.push(std::make_unique<Enemy>("Brutus"));
    enemy_stack.push(std::make_unique<Enemy>("Leroy"));

    //hero declaration
    std::shared_ptr<Hero> hero;

    //check hero for errors after creation
    try {
        hero = Hero::create();
    }catch(TypeException &e){
        std::cout <<"Exception caught: " <<e.what() <<std::endl;
        return 0;
    }catch(StatsException &e){
        std::cout <<"Exception caught: " <<e.what() <<std::endl;
        return 0;
    }
    
    //boss declaration
    std::shared_ptr<Boss> boss;

    //check boss for errors after creation
    try{
        boss = Boss::create();
        hero->show_type();
    }catch(TypeException &e){
        std::cout <<"Exception caught: " <<e.what() <<std::endl;
        return 0;
    }catch(StatsException &e){
        std::cout <<"Exception caught: " <<e.what() <<std::endl;
        return 0;
    }

    //open file for logging
    std::ofstream fout;
    fout.open("game_logs.out");

    //main menu
    start<Boss>(*hero, enemy_stack, *boss, fout);
    
    //close logging
    fout.close();

    return 0;
}