#include "hud.hpp"

Hud::Hud(){
    starter.loadFromFile("tt.png");
    s_starter.setTexture(starter);
}

Hud::~Hud() {}

void Hud::start_bg(sf::RenderWindow& w){
    w.draw(s_starter);

}

void Hud::gameover_bg(sf::RenderWindow& w){
   // w.draw(s_g_over);
}
