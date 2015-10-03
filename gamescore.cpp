#include "gamescore.hpp"

//CONSTRUCTEUR & DESTRUCTEUR
GameScore::GameScore() {}
GameScore::~GameScore() {}

//FONCTION A APPELER DANS LE THREAD
int GameScore::Calcul_Score() //=> Calcul le score qu'effectue le joueur
{ return 0; }

///! TEST
Player GameScore::func()
{
    sf::Texture p;
    p.loadFromFile("bin/img/sprite.png");
    Player player2;
    player2.setTexture(p);


    return player2;
}


