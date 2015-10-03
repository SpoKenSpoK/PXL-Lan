#include "perso.hpp"

//CONSTRUCTEUR & DESCTRUCTEUR:
Player::Player()
    :speed(1), status(running)
{}

Player::~Player(){}

//GETTER & SETTEUR:
int Player::getSpeed() const {return speed;}
void Player::setSpeed(const int&) {speed=_speed}

Status getStatus();
setStatus(const Status&);



