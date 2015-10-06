#include "hud.hpp"

Hud::Hud()
{
    starter.loadFromFile("tt.png");
    s_starter.setTexture(starter);

    over.loadFromFile("tt_end.png");
    s_over.setTexture(over);

    fontText.loadFromFile("Agency FB Bold.ttf");
    highscore.setFont(fontText);
    highscore.setString("- 5 MEILLEURS SCORES -");
    highscore.setCharacterSize(42);

    consigne.setFont(fontText);
    consigne.setString("G pour sauter.\nH pour s'accroupir.\n\nCourrer pour échapper\naux taureaux !\n\nAppuyez sur G pour\ncommencer la partie.\n\nBonne chance !");

    for(int i=0; i<5; ++i) { tabname[i].setFont(fontText); }
    int tmp=42;
    for(int i=0; i<5; ++i){
        tmp-=3;
        tabname[i].setCharacterSize(tmp);
    }
    tabname[0].setColor(sf::Color::Yellow);

}

Hud::~Hud() {}

void Hud::start_bg(sf::RenderWindow& w){
    s_starter.setPosition(w.getSize().x/2 - starter.getSize().x/2,w.getSize().y/2 - starter.getSize().y/2);
    highscore.setPosition(w.getSize().x - 1150,w.getSize().y - 450);
    consigne.setPosition(w.getSize().x - 300,w.getSize().y - 440);

    int tmp=430;
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
    w.draw(consigne);
    for(int i=0; i<5; ++i){ w.draw(tabname[i]); }
}

void Hud::gameover_bg(sf::RenderWindow& w, GameScore& g, bool& b){
    //GESTION ECRITURE DANS LE FICHIER
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        std::ofstream fichier;
        fichier.open("highscore.txt",std::ofstream::out | std::ofstream::app);

        if(fichier){
        fichier<< g.getCompt_i();
        fichier.close();
        }
        b = true;
    }

    w.draw(s_over);
}


/*

 */

std::string Hud::intToString(int i){
    std::ostringstream oss;
    oss << i;
    return oss.str();
}

