#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>



sf::Texture player_texture;

class Player : public sf::Sprite{
private:


public:
    int speed;
    Status status;
    Player();
    //const int getSpeed();
    //void setSpeed(const int);
    //const Status getStatus();
    //void setStatus(const Status);
};

Player::Player()
    :speed(1), status(running)
{}

int main(){
    sf::RenderWindow window(sf::VideoMode(700,200), "Project");
    window.setFramerateLimit(120);

    player_texture.loadFromFile("bin/img/sprite.png");
    Player player;
    player.setTexture(player_texture);
    player.setPosition(window.getSize().x/2 - 32,window.getSize().y - 64);

    bool jump = false;

    while (window.isOpen())
    {
        bool slide = false;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)){
            jump=true;
            slide=false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
            slide=true;
            jump=false;
        }

        if(jump==true && player.getPosition().y > window.getSize().y - 150){
            player.status = jumping;
            slide=false;
            player.move(0,-5);
        }
        else if(player.getPosition().y < window.getSize().y - 64){
            player.move(0,7);
            jump=false;
        }
        if(slide==true){
            player.status = sliding;
            jump=false;
            player.setPosition(player.getPosition().x, window.getSize().y - 64);
            std::cout<<"sliding"<<std::endl;
            //mettre l'animation
        }
        if(!jump && !slide) player.status = running;


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(player);
        window.display();
    }

return 0;
}
