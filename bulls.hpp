#ifndef BULLS_HPP
#define BULLS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class Bulls : public sf::Sprite{
private:
    int speed;
    int Ianimation;
public:
    sf::Texture bull_texture;
    sf::Texture bull_flying_texture;
    bool flying;
    static int bull_space; ///espace entre les taureaux
    static int last_bull; ///index du dernier taureau affich� sur l'ecran
    static int bull_count; ///nombre de taureaux max sur l'ecran
    Bulls();
    ~Bulls();
    void moving();
    void animation();
};

#endif
