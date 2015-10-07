#include "bulls.hpp"
#include <cstdlib>

Bulls::Bulls()
    :speed(5), flying(false)
{
    bull_texture.loadFromFile("bin/img/t1.png");
    this->setTexture(bull_texture);
}

int Bulls::bull_space = 200;
int Bulls::last_bull = 0;
int Bulls::bull_count = 0;

Bulls::~Bulls(){}

void Bulls::moving(){
    this->move(-this->speed, 0);
    if(this->getPosition().x< 0 - this->getGlobalBounds().width){
        this->flying = rand()%2;
        if(!this->flying)
            this->setPosition((bull_count-2)*bull_space + (bull_count-1)*this->getGlobalBounds().width, 500 - this->getGlobalBounds().height);
        if(this->flying)
            this->setPosition((bull_count-2)*bull_space + (bull_count-1)*this->getGlobalBounds().width, 500 - this->getGlobalBounds().height - 100);
    }
}
