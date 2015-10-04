#include "hud.hpp"


Hud::Hud(){
    starter.loadFromFile("tt.png");
}

Hud::~Hud() {}

void Hud::start_bg(sf::RenderWindow& w){

    //sf::sleep(sf::seconds(0.250));

    //sf::sleep(sf::seconds(0.252));
}

void Hud::gameover_bg(sf::RenderWindow& w){
   // w.draw(s_g_over);
}
