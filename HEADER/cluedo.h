#ifndef CLUEDO_CLUEDO_H
#define CLUEDO_CLUEDO_H

#include "libraries.h"
#include "board.h"
#include "player.h"
#include "menu.h"
#include "dice.h"
#include "cards.h"
#include "enveloppe.h"
#include "hypothesis.h"

using namespace std;


class Cluedo {

private:

    sf::RenderWindow m_window;               // Fenêtre de jeu

    vector<Player> m_playerList;              // Liste des joueurs en jeu

    int m_turn;                               // Tour actuel

    Board m_board;                            // Plateau de jeu

    Dices *m_gameDices;                        // Dés du jeu

    Envelope* m_originalGameCards;              // Paquet de carte avant mélange

    Envelope* m_gameCards;                    // Cartes utilisables en jeu

    vector<Card*> m_solution;                // Cartes solutions du jeu

    vector<Menu *> m_menus;                  // Menus du jeu

    unsigned int m_actualMenu;               // Menu actuel

    int m_nbPlayers;                         // Nombre de joueur

    sf::Music m_music;                        // Bande sonore du jeu

    HypothesisModule* m_hypothesisModule;    // Module de formulation des hypothèses

    std::string m_inputText;                 // Texte par défaut au moment de la saise des joueurs

    int m_currentSelectedPlayer;             // Joueur séléctionner dans le menu de saisie des joueurs

    int m_keyPressedCode;                    // Touches appuyée

    string m_password;

    int m_nbenteredPassword;

public:

    Cluedo();

    ~Cluedo() = default;

    void handleEvents();

    void update();

    void display();

    bool isRunning();

    void initButtons();

    void movePlayer(Player &p);

    void nextTurn();

    void initCard();

    void initPlayer();

    void initHypothesis(bool isAccusing);

};

#endif