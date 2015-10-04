#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>

//INCLUDE:
#include "perso.hpp"
#include "gamescore.hpp"
#include "hud.hpp"

//AVANT LE MAIN
std::string intToString(int i) {
     std::ostringstream oss;
     oss << i;
     return oss.str();
}

//DEBUT DU MAIN
sf::Texture player_texture;
sf::Font fontScore;
sf::Text score("", fontScore);

bool game_started=false; ///booleen a vrai tant que le mec a pas perdu

int main(){
    fontScore.loadFromFile("arial.ttf");
    sf::RenderWindow window(sf::VideoMode(1200,500), "Project");
    window.setFramerateLimit(120);

    player_texture.loadFromFile("bin/img/sprite.png");
    Player player;
    player.setTexture(player_texture);
    player.setPosition(window.getSize().x/2 - 32,window.getSize().y - 64);

    GameScore gamescore;
    Hud hud;

    while (window.isOpen())
    {

        if(!game_started){
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::G) || sf::Keyboard::isKeyPressed(sf::Keyboard::H)) game_started = true;
        }
        if(game_started){
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

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            game_started=true; ///mettre a true quand le jeu commence
            std::string temp = "Score: ";
            temp += intToString(gamescore.func(game_started));
            score.setString(temp);
        }

        window.clear();
        window.draw(player);
        window.draw(score);
        window.display();
    }

return 0;
}
