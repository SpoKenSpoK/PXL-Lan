#include "hud.hpp"

Hud::Hud(){
    ///Chargement Textures/Images & Text + Font
    starter.loadFromFile("tt.png");
    over.loadFromFile("tt_end.png");
    s_starter.setTexture(starter);
    s_over.setTexture(over);

    fontText.loadFromFile("Agency FB Bold.ttf");
    highscore.setFont(fontText);
    KeyEntered.setFont(fontText);
    consigne.setFont(fontText);

    highscore.setString("- 5 MEILLEURS SCORES -");
    consigne.setString("G pour sauter.\nH pour s'accroupir.\n\nEvitez les taureaux!\n\nAppuyez sur G pour\ncommencer la partie.\n\nBonne chance !");
    highscore.setCharacterSize(42);
    KeyEntered.setCharacterSize(64);

    ///Affichage du tableau des scores
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

        for(int i=0; i<5; ++i){ fichier >> name[i] >> score[i]; }
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
    sf::Event event;
    std::string scoring;
    scoring += intToString(g.getCompt_i());

    sf::Text TxtScoring(scoring,fontText);
    TxtScoring.setCharacterSize(42);
    TxtScoring.setColor(sf::Color::Yellow);
    TxtScoring.setPosition(w.getSize().x/2 - 85,w.getSize().y/2 - 58);

    while( w.pollEvent(event))
    {
        if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode > 96 && event.text.unicode <123 && _pseudo.length()<4)
            {
                _pseudo += static_cast<char>(event.text.unicode);
            }
            else  if(event.key.code == 8 && _pseudo.length()>= 1){
                std::string temp;
                for(unsigned int i=0; i<_pseudo.length() - 1; ++i){
                    temp+=_pseudo[i];
                }
                _pseudo = temp;
             }
            std::cout<<_pseudo<<std::endl;;
            std::transform(_pseudo.begin(), _pseudo.end(),_pseudo.begin(), ::toupper);
            KeyEntered.setString(_pseudo);
            KeyEntered.setPosition(w.getSize().x - 674 ,w.getSize().y - 230);
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && _pseudo.length()>0)
    {
        sauvegarder(_pseudo,g);
        b = true;
    }
    w.draw(s_over);
    w.draw(TxtScoring);
    w.draw(KeyEntered);
}

void Hud::sauvegarder(std::string& pseudo, GameScore& g){

    int score[5];
    std::string name[5];

    /// LECTURE DU FICHIER
    std::ifstream fichier("highscore.txt", std::ios::in);
    if(fichier){
        for(int i=0; i<5; ++i){ fichier >> name[i] >> score[i]; }

        /// GESTION TRI DES HIGHSCORES
        int index = 0;
        bool index_ok_=true;
        bool nulachier=false;
        for(int i=0; i<5; ++i){
            if(g.getCompt_i() >= score[i]){
                if(index_ok_){
                    index=i;
                    index_ok_=false;
                    nulachier=false;
                }
            }
            else nulachier = true;
        }

        if(!nulachier){
            if(index == 4){
                score[4]=g.getCompt_i();
                name[4]=pseudo;
            }
            else{
                for(int i=3; i>=index; i--)
                {
                    score[i+1]=score[i];
                    name[i+1]=name[i];
                }
                score[index]= g.getCompt_i();
                name[index]= pseudo;
            }
        }
        fichier.close();
    }

    /// ECRITURE DANS LE FICHIER APRES TRI
    std::ofstream fichier_bis;
    fichier_bis.open("highscore.txt",std::ofstream::out /*| std::ofstream::trunc*/);
    if(fichier_bis){
        for(int i=0; i<5; ++i){ fichier_bis <<"\n"<< name[i] << " " << score[i]; }
        fichier_bis.close();
    }

}

std::string Hud::intToString(int i){
    std::ostringstream oss;
    oss << i;
    return oss.str();
}

