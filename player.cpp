#include "player.hpp"

//CONSTRUCTEUR & DESCTRUCTEUR:
Player::Player()
    :speed(10), status(running), Ianimation(0)
{
    texture_run.loadFromFile("bin/img/linerunning.png");
    texture_jump.loadFromFile("bin/img/jump.png");
    texture_slide.loadFromFile("bin/img/slide.png");

    this->setTexture(texture_run);
}

Player::~Player(){}

//GETTER & SETTER:
int Player::getSpeed() const { return speed; }
void Player::setSpeed(const int& _speed) { speed=_speed; }
Status Player::getStatus() const { return status; }
void Player::setStatus(const Status& _status) { status=_status; }
void Player::jump()
{
    this->setStatus(jumping);
    this->move(0,-5);
}
void Player::slide()
{
    this->setStatus(sliding);
}

void Player::animation(int p_animation){
    if(p_animation >=7)
        Ianimation = ((Ianimation+1)%9);

    if(status == running){
        this->setTexture(texture_run);
        this->setTextureRect(sf::IntRect(Ianimation*59,0,59,98));
    }
    if(status == jumping){
        this->setTexture(texture_jump);
        this->setTextureRect(sf::IntRect(0,0,59,98));
    }
    if(status == sliding){
        this->setTexture(texture_slide);
        this->setTextureRect(sf::IntRect(0,0,59,98));
    }
}
