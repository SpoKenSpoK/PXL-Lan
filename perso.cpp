#include "perso.hpp"

//CONSTRUCTEUR & DESCTRUCTEUR:
Player::Player()
    :speed(1), status(running)
{}

Player::~Player(){}

//GETTER & SETTER:
int Player::getSpeed() const { return speed; }
void Player::setSpeed(const int& _speed) { speed=_speed; }
Status getStatus() { return status; }
void Player::setStatus(const Status& _status) { status=_status; }



