#ifndef CLUEDO_ENVELOPPE_H
#define CLUEDO_ENVELOPPE_H

#include "libraries.h"
#include "cards.h"
#include "player.h"

class Envelope {

private:

    vector<Card*> m_cardList;

    sf::Texture m_roomCardTexture;
    sf::Texture m_weaponCardTexture;
    sf::Texture m_playerCardTexture;
    vector<Card*> m_originalCardsList;

public:

    Envelope();

    ~Envelope() = default;

    void fillEnvelope();

    void shuffleEnvelope();

    vector<Card*> getCardList();

    void displayThisCard(int i, sf::RenderWindow *window); // Debug only

    vector<Card*> generateSolution();

    void fillDeck(vector<Player>& playerList, int nbPlayer);

    vector<Card*> getOriginalCardsList();

    vector<Card*> getPlayersCardsList();

    vector<Card*> getWeaponsCardsList();

    vector<Card*> getRoomsCardsList();
};


#endif
