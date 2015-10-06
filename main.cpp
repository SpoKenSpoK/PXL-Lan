#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>

//INCLUDE:
#include "player.hpp"
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
    fontScore.loadFromFile("Agency FB Bold.ttf");
    sf::RenderWindow window(sf::VideoMode(1200,500), "PXL-Lan PROJECT: LineRunner - 2015");
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
            window.clear();
            hud.start_bg(window);
            window.display();

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) game_started = true;
        }

        if(game_started){
            bool jump = false;
            bool slide = false;
            bool dead = false;

            ///GESTION DU CLAVIER & MOUVEMENT DU PERSO

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) dead=true;

            if(dead){
                game_started = false;
                bool name_right = false;

                while(!name_right){
                    window.clear();
                    hud.gameover_bg(window,gamescore,name_right);
                    window.display();
                }
                gamescore.setCompt_f(0);
                dead=false;
            }

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

            std::string temp = "Score: ";
            temp += intToString(gamescore.func(game_started));
            score.setString(temp);

            window.clear();
            window.draw(player);
            window.draw(score);
            window.display();
        }
    }

return 0;
}
