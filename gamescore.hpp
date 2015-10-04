#ifndef GAMESCORE_HPP
#define GAMESCORE_HPP

class GameScore{

private:
    float compt_f; ///compteurs de score
    int compt_i;

public:
    //CONSTRUCTEUR & DESTRUCTEUR
    GameScore();
    ~GameScore();

    //FONCTION A APPELER DANS LE THREAD
    int func(bool&); // => Fonction de test

    //GETTER & SETTER:
    float getCompt_f() const;
    void setCompt_f(const float&);
    int getCompt_i() const;
    void setCompt_i(const int&);

    /// Une fonction qui peut afficher le score en même temps que l'on joue
    /// Afficher le lvl
    /// Afficher le nom
};

#endif // GAMESCORE_HPP
