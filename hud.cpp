#include "hud.hpp"


Hud::Hud(){
    start1.loadFromFile("/bin/img/start1");
    start1.loadFromFile("/bin/img/start2");
    g_over.loadFromFile("/bin/img/gover");

    s_start1.setTexture(start1);
    s_start2.setTexture(start2);
    s_g_over.setTexture(g_over);
}

Hud::~Hud() {}

void Hud::start_bg(sf::RenderWindow& w){
    w.draw(s_start1);
    //sf::sleep(sf::seconds(0.250));

    w.draw(s_start2);
    //sf::sleep(sf::seconds(0.252));
}

void Hud::gameover_bg(sf::RenderWindow& w){
    w.draw(s_g_over);
}
