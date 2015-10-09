#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>

//INCLUDE:
#include "player.hpp"
#include "gamescore.hpp"
#include "hud.hpp"
#include "bulls.hpp"

//DEBUT DU MAIN
sf::Texture player_texture;
sf::Texture bg_texture;
sf::Font fontScore;
sf::Text score("", fontScore);

Bulls* bulls;
bool bulls_created=false;

bool game_started=false; ///booleen a vrai tant que le mec a pas perdu

int main(){
    fontScore.loadFromFile("Agency FB Bold.ttf");
    sf::RenderWindow window(sf::VideoMode(1200,500), "PXL-Lan PROJECT: LineRunner - 2015");
    window.setFramerateLimit(120);

    player_texture.loadFromFile("bin/img/sprite.png");
    Player player;
    player.setTexture(player_texture);
    player.setPosition(window.getSize().x/2 - 32,window.getSize().y - 64);

    bg_texture.loadFromFile("bin/img/background.png");
    sf::Sprite bg;
    bg.setTexture(bg_texture);

    GameScore gamescore;
    Hud hud;

    bool jump_finished = false;

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

            ///creation des taureaux
            if(!bulls_created){
                Bulls::bull_count = (1200 / Bulls::bull_space) + 1;
                bulls = new Bulls[Bulls::bull_count];
                for(int i=0; i<Bulls::bull_count; ++i){
                    bulls[i].flying = rand()%2;
                    if(!bulls[i].flying)
                        bulls[i].setPosition(1201 + (i*Bulls::bull_space) + rand()%100, 500 - bulls[i].getGlobalBounds().height);
                    if(bulls[i].flying)
                        bulls[i].setPosition(1201 + (i*Bulls::bull_space) + rand()%100, 500 - bulls[i].getGlobalBounds().height - 100);
                }
                Bulls::last_bull = Bulls::bull_count - 1;
                bulls_created=true;
            }
            ///fin creation des taureaux
        }

        if(game_started){
            bool jump = false;
            bool slide = false;
            bool dead = false;

            ///GESTION DU CLAVIER & MOUVEMENT DU PERSO
            for (int i=0;i<=Bulls::bull_count;++i)
                if(bulls[i].getGlobalBounds().intersects(player.getGlobalBounds())) dead=true;

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
                delete []bulls;
                Bulls::bull_count=0;
                Bulls::last_bull=0;
                bulls_created=false;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::G) && !jump_finished){ ///faire sauter le perso
                jump=true;
                slide=false;
                player.jump();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)){ ///faire glisser le perso
                slide=true;
                jump=false;
                player.slide();
            }

            if(player.getPosition().y < window.getSize().y - 64 && !jump){ /// si il est en l'air mais qu'il saute pas il retombe
                player.move(0,5);
            }

            if(player.getPosition().y <= window.getSize().y - 150){ jump = false; jump_finished=true;}///faire retomber le perso quand il est en haut



            if(slide==true){ /// le faire glisser
                jump=false;
                player.setPosition(player.getPosition().x, window.getSize().y - 64);
            }

            if(player.getPosition().y >= window.getSize().y - player.getGlobalBounds().height){ jump_finished=false; jump=false; player.setPosition(player.getPosition().x, window.getSize().y - player.getGlobalBounds().height);} /// quand il etait en train de retomber et qu'il a touch� le bas

            if(!jump && !slide) player.setStatus(running); ///si il saute pas et glisse pas il courre

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if(event.type == sf::Event::KeyReleased && player.getPosition().y>0){
                    jump_finished=true;
                    jump=false;
                }
            }

            std::string temp = "Score: ";
            temp += hud.intToString(gamescore.func(game_started));
            score.setString(temp);

            window.clear();
            window.draw(bg);
            for(int i=0; i<Bulls::bull_count; ++i){
                bulls[i].moving();
                window.draw(bulls[i]);
            }
            window.draw(player);
            window.draw(score);
            window.display();
        }
    }
    if(bulls_created)
        delete []bulls;
return 0;
}
