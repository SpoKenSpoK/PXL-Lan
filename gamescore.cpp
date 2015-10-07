#include <iostream>
#include "gamescore.hpp"

//CONSTRUCTEUR & DESTRUCTEUR
GameScore::GameScore()
    :compt_f(0),compt_i(0)
{}
GameScore::~GameScore() {}

//GETTER & SETTER:
float GameScore::getCompt_f() const { return compt_f; }
void GameScore::setCompt_f(const float& f) { compt_f=f; }
int GameScore::getCompt_i() const { return compt_i; }
void GameScore::setCompt_i(const int& i) { compt_i=i; }

//FONCTION A APPELER DANS LE THREAD
int GameScore::func(bool& game_started)
{
    if(game_started){
        setCompt_f(getCompt_f()+0.2);
        setCompt_i(getCompt_f());
        //std::cout<<getCompt_i()<<std::endl;
        return getCompt_i();
    }
    else
        return 0;
}


