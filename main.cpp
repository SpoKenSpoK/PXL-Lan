#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

//INCLUDE:
#include "perso.hpp"
#include "gamescore.hpp"

//DEBUT DU MAIN
sf::Texture player_texture;

float compt_f = 0; ///compteurs de score
int compt_i = 0;
bool game_started=false; ///booleen a vrai tant que le mec a pas perdu

int main(){
    sf::RenderWindow window(sf::VideoMode(1200,500), "Project");
    window.setFramerateLimit(120);

    player_texture.loadFromFile("bin/img/sprite.png");
    Player player;
    player.setTexture(player_texture);
    player.setPosition(window.getSize().x/2 - 32,window.getSize().y - 64);

    while (window.isOpen())
    {
        game_started=true; ///mettre a true quand le jeu commence
        if(game_started){
            compt_f+=0.1;
            compt_i=compt_f;
            std::cout<<compt_i<<std::endl;
        }

        bool jump = false;
        bool slide = false;

        ///GESTION DU CLAVIER & MOUVEMENT DU PERSO

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

        if(slide==true){
            jump=false;
            player.setPosition(player.getPosition().x, window.getSize().y - 64);
            std::cout<<"sliding"<<std::endl;
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
