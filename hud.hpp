#ifndef HUD_HPP
#define HUD_HPP

#include <SFML/Graphics.hpp>


class Hud: public sf::Sprite{
private:


public:
    sf::Texture starter;
    sf::Sprite s_starter;
    //CONSTRUCTEUR & DESTRUCTEUR
    Hud();
    ~Hud();

    //APPEL DES DIFFERENTS BACKGROUND
    void start_bg(sf::RenderWindow&);
    void gameover_bg(sf::RenderWindow&);
};

#endif // HUD_HPP
