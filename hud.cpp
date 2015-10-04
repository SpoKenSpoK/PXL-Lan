#include "hud.hpp"

Hud::Hud(){
    starter.loadFromFile("tt.png");
    s_starter.setTexture(starter);
}

Hud::~Hud() {}

void Hud::start_bg(sf::RenderWindow& w){
    s_starter.setPosition(w.getSize().x/2 - starter.getSize().x/2,w.getSize().y/2 - starter.getSize().y/2);
    w.draw(s_starter);
}

void Hud::gameover_bg(sf::RenderWindow& w){
   // w.draw(s_g_over);
}
