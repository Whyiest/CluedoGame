#ifndef CLUEDO_CARDS_H
#define CLUEDO_CARDS_H

#include "libraries.h"

using namespace std;

class Card {

private:
    string m_cardtype;
    string m_attribut;
    sf::Texture m_cardTexture;
    sf::Sprite m_cardSprite;

public:
    Card(string thisCardType);

    Card(string thisCardType, string thisCardAttribut, sf::Texture thisCardTexture, sf::Sprite thisCardSprite);

    ~Card() = default;

    string getType();

    void display(int startX, int startY, sf::RenderWindow *window);

    string getAttribut();

    sf::Sprite getSprite();
};


#endif
