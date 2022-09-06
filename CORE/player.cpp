#include "../HEADER/player.h"

///*************************************************************************************************************************//

Player::Player(int x, int y, string newPseudo, string newPassword,string skinPath) {
    m_x = x;
    m_y = y;
    m_pseudo = newPseudo;
    m_password = newPassword;
    m_walkPower = 0;
    bool m_hadLaunched = false;
    m_isDead = false;
    m_playerTexture.loadFromImage(util::newImage(skinPath, 50, 50));
    m_playerTexture.setSmooth(true);
    m_skin = skinPath;
}

Player::~Player() = default;

///*************************************************************************************************************************//


void Player::display(sf::RenderWindow *window, int cellWidth, int cellHeight) {

    ///**************************************************************************************************//
    /// La fonction ci-desous permet d'afficher le joueur sur le plateau                                 //
    ///**************************************************************************************************//
    if (ENABLEDEBUG) {
        sf::CircleShape circ;
        circ.setRadius(10);
        circ.setPosition(m_x * cellWidth + circ.getRadius() / 2 + margin / 2,
                         m_y * cellHeight + circ.getRadius() / 2 + margin / 2);
        circ.setFillColor(sf::Color::Red);
        circ.setOutlineColor(sf::Color::Black);
        circ.setOutlineThickness(3);
        window->draw(circ);
    } else {
        m_playerSprite.setTexture(m_playerTexture);
        m_playerSprite.setPosition(m_x * cellWidth + margin / 2,
                                   m_y * cellHeight + margin / 2);
        window->draw(m_playerSprite);
    }
}

void Player::move(int x, int y) {

    ///**************************************************************************************************//
    /// La fonction ci-desous permet de déplacer le joueur sur le plateau                                //
    ///**************************************************************************************************//

    m_x = x;
    m_y = y;
}

void Player::setWalkPower(int range) {

    ///**************************************************************************************************//
    /// Confère au joueur une capacité de déplacement égale au résultat des dés.                         //
    ///**************************************************************************************************//

    m_walkPower = range;
}

void Player::displayDeck(sf::RenderWindow *window) {

    ///**************************************************************************************************//
    ///                         Permet d'afficher le deck du joueur                                      //
    ///**************************************************************************************************//

    int cursor = 0;
    int line = 0;

    for (int i = 0; i <= m_deck.size() - 1; i++) {

        m_deck[i]->display((width * 0.7) + cursor, height * 0.25 + line, window);

        cursor = cursor + 170;

        if (width * 0.7 + cursor > width * 0.94) {

            // Permet de revenir à la ligne quand on arrive au bord
            line = line + 180;
            cursor = 0;
        }
    }

}


void Player::addToDeck(Card *newcard) {

    m_deck.push_back(newcard);
}

///**************************************************************************************************//
///                                        GETTER                                                    //
///**************************************************************************************************//

string Player::getPseudo() {
    return m_pseudo;
}

int Player::getWalkPower() {
    return m_walkPower;
}

int Player::getX() {
    return m_x;
}

int Player::getY() {
    return m_y;
}

vector<Card *> Player::getDeck() {
    return m_deck;
}

bool Player::getHasLaunched() {
    return m_hasLaunched;
}

void Player::setHasLaunched(bool didHeLaunch) {
    m_hasLaunched = didHeLaunch;
}

void Player::kill() {
    m_isDead = true;
}
bool Player::getIsDead() {
    return m_isDead;
}

string Player::getSkin() {
    return m_skin;
}


