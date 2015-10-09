#include "player.hpp"

//CONSTRUCTEUR & DESCTRUCTEUR:
Player::Player()
    :speed(10), status(running)
{}

Player::~Player(){}

//GETTER & SETTER:
int Player::getSpeed() const { return speed; }
void Player::setSpeed(const int& _speed) { speed=_speed; }
Status Player::getStatus() const { return status; }
void Player::setStatus(const Status& _status) { status=_status; }
void Player::jump()
{
    this->setStatus(jumping);
    this->move(0,-3);
}
void Player::slide()
{
    this->setStatus(sliding);
}
