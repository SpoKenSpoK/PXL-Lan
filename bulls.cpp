#include "bulls.hpp"
#include <cstdlib>

Bulls::Bulls()
    :speed(3),Ianimation(0), flying(false)
{
    bull_texture.loadFromFile("bin/img/bull.png");
    bull_flying_texture.loadFromFile("bin/img/bull_flying.png");
}

int Bulls::bull_space = 200;
int Bulls::last_bull = 0;
int Bulls::bull_count = 0;

Bulls::~Bulls(){}

void Bulls::moving(){
    this->move(-this->speed, 0);
    if(this->getPosition().x< 0 - this->getGlobalBounds().width){
        this->flying = rand()%2;
        if(!this->flying){
            this->setTexture(bull_texture);
            this->setTextureRect(sf::IntRect(0,0,89,50));
            this->setPosition((bull_count)*(bull_space+this->getGlobalBounds().width) - rand()%100, 500 - this->getGlobalBounds().height);
        }
        if(this->flying){
            this->setTexture(bull_flying_texture);
            this->setTextureRect(sf::IntRect(0,0,89,52));
            this->setPosition((bull_count)*(bull_space+this->getGlobalBounds().width) - rand()%100, 500 - this->getGlobalBounds().height - 75);
        }
    }
}
//this->setPosition((bull_count-2)*bull_space + (bull_count-1)*this->getGlobalBounds().width + rand()%100, 500 - this->getGlobalBounds().height);
void Bulls::animation(){
    Ianimation = ((Ianimation+1)%4);
    if(this->flying)
        this->setTextureRect(sf::IntRect(Ianimation*89,0,89,52));
    if(!this->flying)
        this->setTextureRect(sf::IntRect(Ianimation*89,0,89,50));
}
