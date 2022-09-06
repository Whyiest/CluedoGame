
#ifndef CLUEDO_HYPOTHESIS_H
#define CLUEDO_HYPOTHESIS_H

#include "libraries.h"
#include "player.h"
#include "cards.h"

class HypothesisModule {

private:

    vector<Player> m_listPlayer;
    Player *m_accuser;

    int m_numWeapon;
    int m_numPlayer;
    int m_numRoom;

    int m_weaponIterator;
    int m_playerIterator;

    string m_targetPlayer;
    Card* m_targetCard;


    int m_actualTurn;
    bool m_isAccusing;

    vector<Card *> m_copyOfOriginalCards;
    vector<Card *> m_hypothesis;
    vector<Card *> m_solutionOfTheGame;

public:

    HypothesisModule(vector<Player> &listPlayer, int actualTurn, vector<Card *> solution, bool isAccusing);

    ~HypothesisModule() = default;

    void copyOriginalCards(vector<Card *> originalCards);

    void displayChoice(sf::RenderWindow *window);

    void displaySolution(sf::RenderWindow *window);

    void displayHypothesis(sf::RenderWindow *window);

    void createHypothesis();

    void searchNumRoom(string roomToSearch);

    void verifyHypothesis ();

    bool verifySolution();

    void nextWeaponIterator();

    void backWeaponIterator();

    void nextPlayerIterator();

    void backPlayerIterator();

    bool checkIfAccusing();

    vector<Card *> getHypothesis();
};

#endif
