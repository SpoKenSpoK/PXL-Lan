#ifndef HUD_HPP
#define HUD_HPP

#include <SFML/Graphics.hpp>


class Hud: public sf::Sprite{
private:


public:
    sf::Texture start1;
    sf::Texture start2;
    sf::Texture g_over;

    sf::Sprite s_start1;
    sf::Sprite s_start2;
    sf::Sprite s_g_over;
    //CONSTRUCTEUR & DESTRUCTEUR
    Hud();
    ~Hud();

    //APPEL DES DIFFERENTS BACKGROUND
    void start_bg(sf::RenderWindow&);
    void gameover_bg(sf::RenderWindow&);
};

#endif // HUD_HPP
