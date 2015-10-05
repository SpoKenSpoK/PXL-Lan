#include "hud.hpp"


Hud::Hud(){
    starter.loadFromFile("tt.png");
    s_starter.setTexture(starter);

    fontText.loadFromFile("arial.ttf");
    highscore.setFont(fontText);
    highscore.setString("Meilleurs Scores : ");
    name_1.setFont(fontText);
    name_1.setColor(sf::Color::Yellow);
    name_2.setFont(fontText);
    name_3.setFont(fontText);
    name_4.setFont(fontText);
    name_5.setFont(fontText);
}

Hud::~Hud() {}

void Hud::start_bg(sf::RenderWindow& w){
    s_starter.setPosition(w.getSize().x/2 - starter.getSize().x/2,w.getSize().y/2 - starter.getSize().y/2);

    highscore.setPosition(w.getSize().x - 1150,w.getSize().y - 500);
    name_1.setPosition(w.getSize().x - 1150,w.getSize().y - 450);
    name_2.setPosition(w.getSize().x - 1150,w.getSize().y - 400);
    name_3.setPosition(w.getSize().x - 1150,w.getSize().y - 350);
    name_4.setPosition(w.getSize().x - 1150,w.getSize().y - 300);
    name_5.setPosition(w.getSize().x - 1150,w.getSize().y - 250);


    std::ifstream fichier("highscore.txt", std::ios::in); ///Ouverture du fichier en lecture
    if(fichier){

        int score1, score2, score3, score4, score5;
        std::string name1, name2, name3, name4, name5;

        fichier >> name1 >> score1 >> name2 >> score2 >> name3 >> score3 >> name4 >> score4 >> name5 >> score5;
        name_1.setString(name1);
        name_2.setString(name2);
        name_3.setString(name3);
        name_4.setString(name4);
        name_5.setString(name5);

        fichier.close();  /// Fermeture du fichier
    }

    else
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;

    w.draw(s_starter);
    w.draw(highscore);
    w.draw(name_1);
    w.draw(name_2);
    w.draw(name_3);
    w.draw(name_4);
    w.draw(name_5);
}

void Hud::gameover_bg(sf::RenderWindow& w){
   // w.draw(s_g_over);
}
