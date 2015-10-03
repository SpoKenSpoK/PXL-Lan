#ifndef GAMESCORE_HPP
#define GAMESCORE_HPP

#include "perso.hpp"

class GameScore: public Player{
public:
    //CONSTRUCTEUR & DESTRUCTEUR
    GameScore();
    ~GameScore();

    //FONCTION A APPELER DANS LE THREAD
    int Calcul_Score();
    Player func(); // => Fonction de test

    /// Une fonction qui peut afficher le score en même temps que l'on joue
    /// Afficher le lvl
    /// Afficher le nom
};

#endif // GAMESCORE_HPP
