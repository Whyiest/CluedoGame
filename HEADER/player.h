#ifndef CLUEDO_PLAYER_H
#define CLUEDO_PLAYER_H

#include "libraries.h"
#include "iostream"
#include "cell.h"
#include "board.h"
#include "cards.h"

using namespace std;

    class Player {

    private:

        int m_x;

        int m_y;

        int m_walkPower;

        string m_pseudo;     // Identifiant du compte

        string m_password;  // Mot de passe

        string m_skin;

        vector<Card *> m_deck;

        bool m_hasLaunched;

        sf::Texture m_playerTexture;

        sf::Sprite m_playerSprite;

        bool m_isDead;

    public:

        Player(int x, int y, string newPseudo, string newPassword, std::string skinPath);

        ~Player();

        void move(int x, int y);

        void setWalkPower(int range);

        string getPseudo();

        string getSkin();

        int getWalkPower();

        int getX();

        int getY();

        void display(sf::RenderWindow *window, int cellWidth, int cellHeight);

        void displayDeck(sf::RenderWindow *window);

        void addToDeck(Card *newcard);

        vector<Card *> getDeck();

        bool getHasLaunched();

        void setHasLaunched(bool didHeLaunch);

        bool getIsDead();

        void kill();

    };

#endif
