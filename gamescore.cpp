#include <iostream>
#include "gamescore.hpp"

//CONSTRUCTEUR & DESTRUCTEUR
GameScore::GameScore() {}
GameScore::~GameScore() {}

//FONCTION A APPELER DANS LE THREAD
int GameScore::Calcul_Score() //=> Calcul le score qu'effectue le joueur
{ return 0; }

///! TEST
void GameScore::func()
{
    for(int i=0; i<10;++i)
        std::cerr<<"LoL"<<std::endl;
}


