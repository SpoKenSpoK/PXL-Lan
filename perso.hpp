#ifndef PLAYER_HPP
#define PLAYER_HPP

enum Status{jumping, running, sliding}; //ENUMERATION UTILISEE DANS LA CLASSE PLAYER

class Player: public sf::Sprite{
private:
    int speed; //Vitesse du personnage
    Status status; //Status du perso: Sauter - Se baisser - Courrir

public:
    //CONSTRUCTEUR & DESTRUCTEUR
    Player();
    ~Player();

    // GETTER & SETTER:
    int getSpeed() const;
    void setSpeed(const int&);
    Status getStatus() const;
    setStatus(const Status&);
};

#endif // PLAYER_HPP
