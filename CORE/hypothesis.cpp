#include "../HEADER/hypothesis.h"
///*************************************************************************************************************************//


HypothesisModule::HypothesisModule(vector<Player> &listPlayer, int actualTurn,
                                   vector<Card *> solution, bool isAccusing) {
    m_listPlayer = listPlayer;
    m_actualTurn = actualTurn;
    m_solutionOfTheGame = solution;
    m_weaponIterator = 14;
    m_playerIterator = 20;
    m_numWeapon = m_weaponIterator;
    m_numPlayer = m_playerIterator;
    m_isAccusing = isAccusing;
}

///*************************************************************************************************************************//


void HypothesisModule::copyOriginalCards(vector<Card *> originalCards) {

    ///**************************************************************************************************//
    /// Cette fonction procure à la classe une copie des cartes originales (non mélangées) du jeu.       //
    ///**************************************************************************************************//
    m_copyOfOriginalCards = originalCards;
}

void HypothesisModule::createHypothesis() {

    ///**************************************************************************************************//
    ///  Permet au joueur de créer une hypothèse  selon ses choix dans le menu                           //
    ///**************************************************************************************************//

    // Ordre de la solution du jeu : weapon --> room --> player

    m_hypothesis.push_back(m_copyOfOriginalCards[m_numWeapon]);
    m_hypothesis.push_back(m_copyOfOriginalCards[m_numRoom]);
    m_hypothesis.push_back(m_copyOfOriginalCards[m_numPlayer]);

    cout << "[HYPOTHESE CREE] - Donnee de l'hypothese :\n\n";
    for (int i = 0; i <= 2; i++) {
        cout << " Carte " << m_hypothesis[i]->getType() << " d'hypothese : " << m_hypothesis[i]->getAttribut() << " \n";
    }
    cout << "Joueur createur : " << m_listPlayer[m_actualTurn].getPseudo() << " \n";
    cout << "------------------------\n\n";
}

void HypothesisModule::searchNumRoom(string roomToSearch) {

    ///**************************************************************************************************//
    /// Permet d'identifier sur quelle case se trouve le joueur, et d'en tirer la carte correspondante   //
    ///**************************************************************************************************//

    int temp = 0;

    for (int i = 0; i <= m_copyOfOriginalCards.size() - 1; i++) {
        if (m_copyOfOriginalCards[i]->getAttribut() == roomToSearch) {
            temp = i;
        }
    }
    cout << "[SUCCES] : Le programme a determine que la carte lieu " << roomToSearch
         << " sur laquelle se trouve le joueur formulant l'hypothese, se trouvais en position " << temp
         << " du paquet original de carte.\n\n";
    m_numRoom = temp;
}


void HypothesisModule::displayChoice(sf::RenderWindow *window) {

    ///**************************************************************************************************//
    /// Permet d'afficher les choix déroulant du menu de saisie de l'hypothèse.                          //
    ///**************************************************************************************************//

    sf::Sprite copyWeaponSprite = m_copyOfOriginalCards[m_weaponIterator]->getSprite();
    sf::Sprite copyPlayerSprite = m_copyOfOriginalCards[m_playerIterator]->getSprite();
    sf::Sprite copyRoomSprite = m_copyOfOriginalCards[m_numRoom]->getSprite();

    copyWeaponSprite.setScale(1.35f, 1.35f);
    copyWeaponSprite.setPosition(width * 0.10, width * 0.135);
    window->draw(copyWeaponSprite);

    copyPlayerSprite.setScale(1.60f, 1.60f);
    copyPlayerSprite.setPosition(width * 0.41, width * 0.135);
    window->draw(copyPlayerSprite);

    copyRoomSprite.setScale(1.30f, 1.30f);
    copyRoomSprite.setPosition(width * 0.72, width * 0.135);
    window->draw(copyRoomSprite);
}

void HypothesisModule::displaySolution(sf::RenderWindow *window) {

    ///**************************************************************************************************//
    /// Permet d'afficher à l'écran la solution du jeu                                                   //
    ///**************************************************************************************************//

    sf::Sprite copyWeaponSprite = m_solutionOfTheGame[0]->getSprite();
    sf::Sprite copyPlayerSprite = m_solutionOfTheGame[2]->getSprite();
    sf::Sprite copyRoomSprite = m_solutionOfTheGame[1]->getSprite();

    copyWeaponSprite.setScale(1.35f, 1.35f);
    copyWeaponSprite.setPosition(width * 0.10, width * 0.17);
    window->draw(copyWeaponSprite);

    copyPlayerSprite.setScale(1.60f, 1.60f);
    copyPlayerSprite.setPosition(width * 0.41, width * 0.17);
    window->draw(copyPlayerSprite);

    copyRoomSprite.setScale(1.30f, 1.30f);
    copyRoomSprite.setPosition(width * 0.72, width * 0.17);
    window->draw(copyRoomSprite);
}


void HypothesisModule::verifyHypothesis() {

    ///*****************************************************************************************************//
    /// Permet de convertir l'hypothèse du joueur en cartes, afin de vérifier facilement l'hypothèse        //
    ///*****************************************************************************************************//

    int iteratorCardToDisplay = 50;
    int iteratorPlayer = 50;


    // Ce qui est intéréssant ici, c'est que l'itérateur pourra changer plusieurs fois de valeur durant cette boucle,
    // si le joueur possède plusieurs carte par exemple. Cela ajoute donc un côté aléatoire au reveal de carte.


    for (int z = 0; z <= m_listPlayer.size() - 1; z++) { // Pour chaque joueur

        for (int i = 0; i <= m_listPlayer[z].getDeck().size() - 1; i++) {  // Pour chaque carte du joueur

            for (int j = 0; j <= 2; j++) {              //Pour chaque carte de l'hypothèse.

                if (m_listPlayer[z].getDeck()[i]->getAttribut() == m_hypothesis[j]->getAttribut() &&
                    m_actualTurn != z) {

                    iteratorCardToDisplay = i;      // Au cours de la boucle,
                    iteratorPlayer = z;
                }
            }
        }
    }


    if (iteratorCardToDisplay != 50) {

        //------------------------------------------- DEBUG--------------------------------//
        cout << "[DEBUG] Carte trouver correspondant a l'hypothese. Les donnes trouvee sont les suivantes :\n "
             << "Valeur de iteratorCardToDisplay : " << iteratorCardToDisplay << "\n"
             << "Valeur de iteratorPlayer : " << iteratorPlayer << " \n";

        cout << "Carte de" << m_listPlayer[iteratorPlayer].getPseudo() << " pour ces valeurs : " << m_listPlayer[iteratorPlayer].getDeck()[iteratorCardToDisplay]->getAttribut() << "\n";
        for (int i = 0; i <= m_listPlayer[iteratorPlayer].getDeck().size() -1 ; i ++ ) {
            cout << m_listPlayer[iteratorPlayer].getDeck()[i]->getAttribut() << " + ";
        }
        //------------------------------------------- DEBUG--------------------------------//


        m_targetCard = m_listPlayer[iteratorPlayer].getDeck()[iteratorCardToDisplay];
        m_targetPlayer = m_listPlayer[iteratorPlayer].getPseudo();

    } else {

        cout << "[DEBUG] Aucune carte trouvee.\n Valeur de iteratorCardToDisplay : " << iteratorCardToDisplay
             << " et de iteratorPlayer : " << iteratorPlayer << " \n\n";

        m_targetPlayer = "None"; // Si le joueur trouve la solution du premier coup.
    }


}

void HypothesisModule::displayHypothesis(sf::RenderWindow *window) {


    ///*****************************************************************************************************//
    /// Permet d'afficher les différents choix de cartes pour formuler une hypothèse                        //
    ///*****************************************************************************************************//

    string fontPath = "../DATA/Fonts/In your face, joffrey!.ttf";


    if (m_targetPlayer == "None") {

        // Quand le joueur trouve la bonne combinaison du premier coup.

        util::displayText(width * 0.3f + 100, height * 0.20f + 15, 50,
                          "Personne ne possede une des cartes", fontPath,
                          window); // Attention accent
        util::displayText(width * 0.4f + 40, height * 0.75f + 5, 50, "Bonne intuition !", fontPath, window);
    } else {

        util::displayText(width * 0.3f + 100, height * 0.20f + 15, 50, "Un joueur vous revele sa carte :", fontPath,
                          window); // Attention accent
        util::displayText(width * 0.4f + 40, height * 0.75f + 5, 50, m_targetPlayer, fontPath, window);

        sf::Sprite copyToDisplay = m_targetCard->getSprite();
        copyToDisplay.setPosition(width * 0.42f, height * 0.30f);
        copyToDisplay.setScale(1.2f, 1.2f);
        window->draw(copyToDisplay);
    }
}


bool HypothesisModule::verifySolution() {

    ///*******************************************************************************************************//
    /// Compare le résultat du traitement de l'hypothèse avec les solutions du jeu. Retourne true si solution //
    ///*******************************************************************************************************//

    int matchCounter = 0;

    for (int i = 0; i <= 2; i++) {
        if (m_hypothesis[i] == m_solutionOfTheGame[i]) {
            matchCounter++;
        }
    }

    if (matchCounter == 3) return true;
    else return false;
}

void HypothesisModule::nextWeaponIterator() {

    if (m_weaponIterator + 1 <= 16) {
        m_weaponIterator++;
        m_numWeapon = m_weaponIterator;
    }
}

void HypothesisModule::backWeaponIterator() {

    if (m_weaponIterator - 1 >= 11) {
        m_weaponIterator--;
        m_numWeapon = m_weaponIterator;
    }
}

void HypothesisModule::nextPlayerIterator() {

    if (m_playerIterator + 1 <= 25) {
        m_playerIterator++;
        m_numPlayer = m_playerIterator;
    }
}

void HypothesisModule::backPlayerIterator() {

    if (m_playerIterator - 1 >= 17) {
        m_playerIterator--;
        m_numPlayer = m_playerIterator;
    }
}

bool HypothesisModule::checkIfAccusing() {
    return m_isAccusing;
}

vector<Card *> HypothesisModule::getHypothesis() {
    return m_hypothesis;
}



