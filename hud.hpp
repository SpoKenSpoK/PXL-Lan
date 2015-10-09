#ifndef HUD_HPP
#define HUD_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include "gamescore.hpp"


class Hud: public sf::Sprite{
private:
    sf::Texture starter;
    sf::Sprite s_starter;
    sf::Texture over;
    sf::Sprite s_over;
    sf::Font fontText;
    sf::Text highscore;
    sf::Text consigne;
    sf::Text KeyEntered;
    sf::Text tabname[5];
    std::string _pseudo;

public:
    //CONSTRUCTEUR & DESTRUCTEUR
    Hud();
    ~Hud();

    void setPseudo(const std::string&);

    //APPEL DES DIFFERENTS BACKGROUND
    void start_bg(sf::RenderWindow&);
    void gameover_bg(sf::RenderWindow&, GameScore&,bool&);
    void sauvegarder(std::string&, GameScore&);
    std::string intToString(int);
};

#endif // HUD_HPP
