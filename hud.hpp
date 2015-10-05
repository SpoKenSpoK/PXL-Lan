#ifndef HUD_HPP
#define HUD_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class Hud: public sf::Sprite{
private:
    sf::Texture starter;
    sf::Sprite s_starter;
    sf::Font fontText;

    sf::Text highscore;
    sf::Text name_1;
    sf::Text name_2;
    sf::Text name_3;
    sf::Text name_4;
    sf::Text name_5;

public:
    //CONSTRUCTEUR & DESTRUCTEUR
    Hud();
    ~Hud();

    //APPEL DES DIFFERENTS BACKGROUND
    void start_bg(sf::RenderWindow&);
    void gameover_bg(sf::RenderWindow&);
    void charger_sauvegarde();
};

#endif // HUD_HPP
