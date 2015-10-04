#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

//INCLUDE:
#include "perso.hpp"
#include "gamescore.hpp"

//DEBUT DU MAIN
sf::Texture player_texture;

int main(){
    sf::RenderWindow window(sf::VideoMode(1200,500), "Project");
    window.setFramerateLimit(120);

    player_texture.loadFromFile("bin/img/sprite.png");
    Player player;
    player.setTexture(player_texture);
    player.setPosition(window.getSize().x/2 - 32,window.getSize().y - 72);



    while (window.isOpen())
    {

        bool jump = false;
        bool slide = false; /// ! GESTION DU CLAVIER A METTRE DANS UNE CLASSE MOUVEMENT (par exemple)

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)){
            jump=true;
            slide=false;

            player.jump();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
            slide=true;
            jump=false;

            player.slide();
        }

        if(jump==true && player.getPosition().y > window.getSize().y - 150){
            slide=false;
        }
        else if(player.getPosition().y < window.getSize().y - 64){
            player.move(0,5);
            jump=false;
        }
        if(!jump && !slide) player.setStatus(running);



        ///! CHANTIER !///////////////

 /*
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)){
                while(player.getPosition().y > window.getSize().y - 150)
                    player.jump();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
                while(player.getPosition().y < window.getSize().y - 64)
                    player.slide();
        }

        else if ( (player.getPosition().y > window.getSize().y - 150) && (player.getPosition().y < window.getSize().y - 64))
            player.move(0,5);
*/

        ///! FIN CHANTIER !!///////


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ///!!!! TEST THREAD !!!!///

        GameScore object;
        sf::Thread thread(&GameScore::func, &object);
        thread.launch();

        ///!!!! FIN TEST THREAD !!!!///

        window.clear();
        window.draw(player);
        window.display();
    }

return 0;
}
