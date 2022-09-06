#ifndef CLUEDO_DICE_H
#define CLUEDO_DICE_H

#include "libraries.h"
#include "vector"

using namespace  std;

class Dices {

private:

    int m_resultat1;
    int m_resultat2;
    int m_resultatotal;

    int m_diceWidth;
    int m_diceHeight;

    // Pour le premier dé

    int m_dice1posX;
    int m_dice1posY;

    // Pour le second dé

    int m_dice2posX;
    int m_dice2posY;

    // Gestion de la texture

    sf::Texture m_diceTexture;
    vector<sf::Sprite> m_listeSprite;

public:

    Dices(sf::RenderWindow *window);
    ~Dices();

    void initialiser();

    void lancer(sf::RenderWindow *window);
    void displayDices(sf::RenderWindow *window);

    int getResultat1();
    int getResultat2();
    int getPos1X();
    int getPos1Y();
    int getResultat();
};


#endif