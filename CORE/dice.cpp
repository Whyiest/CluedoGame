#include "../HEADER/dice.h"
#include "../HEADER/utilitaire.h"

using namespace std;

///*************************************************************************************************************************//

Dices::Dices(sf::RenderWindow *window) {

    m_resultat1 = 6;
    m_resultat2 = 6;
    m_resultatotal = 0;

    // Hauteur et largeur de chaque dés.

    m_diceWidth = 1.5;
    m_diceHeight = 1.5;

    // On calcul la position du dé numéro 1 en fonction de la taille de la fenêtre

    m_dice1posX = width - (width * 0.23);
    m_dice2posX = m_dice1posX + 120;

    // On calcul la position du dé numéro deux en fonction du premier et de sa largeur/hauteur.

    m_dice1posY = height - (height * 0.92);
    m_dice2posY = m_dice1posY;

    Dices::initialiser();
}

Dices::~Dices() { }

///*************************************************************************************************************************//


int Dices::getPos1X(){
    return m_dice1posX;
}

int Dices::getPos1Y(){
    return m_dice1posY;
}

int Dices::getResultat(){
    return m_resultatotal;
}


void Dices::lancer(sf::RenderWindow *window) {

    ///**************************************************************************************************///
    /// Cette fonction permet de générer les résultats de deux lancés aléatoires de dés                  ///
    ///**************************************************************************************************///

        m_resultat1 = util::random(1, 6);
        m_resultat2 = util::random(1, 6);
        m_resultatotal = m_resultat1 + m_resultat2;
}


void Dices::initialiser() {

    ///**************************************************************************************************//
    /// La fonction permet d'initialiser les dés, en définissant une image pour chaque face du dé        //
    ///**************************************************************************************************//

    sf::Sprite dice1;
    sf::Sprite dice2;
    sf::Sprite dice3;
    sf::Sprite dice4;
    sf::Sprite dice5;
    sf::Sprite dice6;

    // Initialisation de la texture globale :

    m_diceTexture.loadFromFile("../DATA/Others/imageDice3.png");

    // Préparation des Sprite, en leur indiquant la texture cible:

    dice1.setTexture(m_diceTexture);
    dice2.setTexture(m_diceTexture);
    dice3.setTexture(m_diceTexture);
    dice4.setTexture(m_diceTexture);
    dice5.setTexture(m_diceTexture);
    dice6.setTexture(m_diceTexture);

    // Aggrandissement (pour le plaisir visuel) :

    dice1.setScale(m_diceWidth, m_diceHeight);
    dice2.setScale(m_diceWidth, m_diceHeight);
    dice3.setScale(m_diceWidth, m_diceHeight);
    dice4.setScale(m_diceWidth, m_diceHeight);
    dice5.setScale(m_diceWidth, m_diceHeight);
    dice6.setScale(m_diceWidth, m_diceHeight);

    // Découpage de la texture

    dice1.setTextureRect(sf::IntRect(6, 4, 76, 77));
    dice2.setTextureRect(sf::IntRect(88, 4, 78, 77));
    dice3.setTextureRect(sf::IntRect(175, 4, 78, 77));
    dice4.setTextureRect(sf::IntRect(4, 102, 78, 77));
    dice5.setTextureRect(sf::IntRect(88, 102, 78, 77));
    dice6.setTextureRect(sf::IntRect(175, 102, 78,77));


    m_listeSprite.push_back(dice1); // En cas d'erreur, cela permet d'avoir une réponse graphique même en appelant l'indice 0 du tableau.
                                    // En pratique cette case ne sera pas utilisé pour de raisons de compréhension du code.

    for (int i = 0; i < 2; i++) {
        m_listeSprite.push_back(dice1); // Résultat du dé 1
        m_listeSprite.push_back(dice2); // Résultat du dé 2
        m_listeSprite.push_back(dice3); // Résultat du dé 3
        m_listeSprite.push_back(dice4); // Résultat du dé 4
        m_listeSprite.push_back(dice5); // Résultat du dé 5
        m_listeSprite.push_back(dice6); // Résultat du dé 6
    }
}

void Dices::displayDices(sf::RenderWindow *window) {

    ///**************************************************************************************************//
    /// La fonction ci-desous permet l'affichage des dés, une fois que ces derniers ont été lancés       //
    ///**************************************************************************************************//

    switch (m_resultat1) {

        case 1 : {
            m_listeSprite[1].setPosition(m_dice1posX, m_dice1posY);
            window->draw(m_listeSprite[1]);
            break;

        }
        case 2 : {
            m_listeSprite[2].setPosition(m_dice1posX, m_dice1posY);
            window->draw(m_listeSprite[2]);
            break;
        }
        case 3 : {
            m_listeSprite[3].setPosition(m_dice1posX, m_dice1posY);
            window->draw(m_listeSprite[3]);
            break;
        }
        case 4 : {
            m_listeSprite[4].setPosition(m_dice1posX, m_dice1posY);
            window->draw(m_listeSprite[4]);
            break;
        }
        case 5 : {
            m_listeSprite[5].setPosition(m_dice1posX, m_dice1posY);
            window->draw(m_listeSprite[5]);
            break;
        }
        case 6 : {
            m_listeSprite[6].setPosition(m_dice1posX, m_dice1posY);
            window->draw(m_listeSprite[6]);
            break;
        }
    }

    switch (m_resultat2) {

        case 1 : {
            m_listeSprite[7].setPosition(m_dice2posX, m_dice2posY);
            window->draw(m_listeSprite[7]);
            break;
        }
        case 2 : {
            m_listeSprite[8].setPosition(m_dice2posX, m_dice2posY);
            window->draw(m_listeSprite[8]);
            break;
        }
        case 3 : {
            m_listeSprite[9].setPosition(m_dice2posX, m_dice2posY);
            window->draw(m_listeSprite[9]);
            break;
        }
        case 4 : {
            m_listeSprite[10].setPosition(m_dice2posX, m_dice2posY);
            window->draw(m_listeSprite[10]);
            break;
        }
        case 5 : {
            m_listeSprite[11].setPosition(m_dice2posX, m_dice2posY);
            window->draw(m_listeSprite[11]);
            break;
        }
        case 6 : {
            m_listeSprite[12].setPosition(m_dice2posX, m_dice2posY);
            window->draw(m_listeSprite[12]);
            break;
        }
    }
}