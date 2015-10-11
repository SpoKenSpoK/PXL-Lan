#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

enum Status{jumping, running, sliding}; //ENUMERATION UTILISEE DANS LA CLASSE PLAYER

class Player: public sf::Sprite{
private:
    int speed; //Vitesse du personnage
    Status status; //Status du perso: Sauter - Se baisser - Courrir

public:
    //CONSTRUCTEUR & DESTRUCTEUR
    Player();
    ~Player();
    sf::Texture texture_run;
    sf::Texture texture_jump;
    sf::Texture texture_slide;

    // GETTER & SETTER:
    int getSpeed() const;
    void setSpeed(const int&);
    Status getStatus() const;
    void setStatus(const Status&);
    void jump();
    void slide();
    void animation();
};

#endif // PLAYER_HPP
