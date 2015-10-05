#include "hud.hpp"

Hud::Hud()
{
    starter.loadFromFile("tt.png");
    s_starter.setTexture(starter);

    fontText.loadFromFile("arial.ttf");
    highscore.setFont(fontText);
    highscore.setString("Meilleurs Scores : ");

    for(int i=0; i<5; ++i) { tabname[i].setFont(fontText); }
    tabname[0].setColor(sf::Color::Yellow);
}

Hud::~Hud() {}

void Hud::start_bg(sf::RenderWindow& w){
    s_starter.setPosition(w.getSize().x/2 - starter.getSize().x/2,w.getSize().y/2 - starter.getSize().y/2);

    highscore.setPosition(w.getSize().x - 1150,w.getSize().y - 500);

    int tmp=500;
    for(int i=0; i<5; i++)
    {
        tmp-=50;
        tabname[i].setPosition(w.getSize().x - 1150,w.getSize().y - tmp);
    }

    std::ifstream fichier("highscore.txt", std::ios::in); ///Ouverture du fichier en lecture
    if(fichier){

        int score[5];
        std::string name[5];

        for(int i=0; i<5; ++i){
            fichier >> name[i]
                    >> score[i];
        }

        for(int i=0; i<5; ++i){
            name[i]+= " : ";
            name[i]+= intToString(score[i]);
            tabname[i].setString(name[i]);
        }

        fichier.close();  /// Fermeture du fichier
    }

    else
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;

    w.draw(s_starter);
    w.draw(highscore);
    for(int i=0; i<5; ++i){ w.draw(tabname[i]); }
}

void Hud::gameover_bg(sf::RenderWindow& w){
   // w.draw(s_g_over);
}

std::string Hud::intToString(int i){
    std::ostringstream oss;
    oss << i;
    return oss.str();
}

