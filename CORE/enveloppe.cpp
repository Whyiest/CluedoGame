#include "../HEADER/enveloppe.h"

///*************************************************************************************************************************//

Envelope::Envelope() {}

///*************************************************************************************************************************//


void Envelope::fillEnvelope() {

    ///****************************************************************************************************//
    /// La fonction ci-dessous permet de remplir l'enveloppe du jeu et load les images correspondantes     //
    ///****************************************************************************************************//



    /// Définition des textures :

    m_playerCardTexture.loadFromFile("../DATA/Cards/playerCards.png");
    m_roomCardTexture.loadFromFile("../DATA/Cards/roomCards.png");
    m_weaponCardTexture.loadFromFile("../DATA/Cards/weaponCards.png");

    /// Définition des cartes rooms (0 à 10)

    float scaleFactorRooms = 0.5;

    sf::Sprite upperEngine;
    sf::Sprite cafeteria;
    sf::Sprite medbay;
    sf::Sprite security;
    sf::Sprite reactor;
    sf::Sprite weapons;
    sf::Sprite lowerEngine;
    sf::Sprite electrical;
    sf::Sprite storage;
    sf::Sprite admin;
    sf::Sprite shields;

    upperEngine.setScale(scaleFactorRooms, scaleFactorRooms);
    cafeteria.setScale(scaleFactorRooms, scaleFactorRooms);
    medbay.setScale(scaleFactorRooms, scaleFactorRooms);
    security.setScale(scaleFactorRooms, scaleFactorRooms);
    reactor.setScale(scaleFactorRooms, scaleFactorRooms);
    weapons.setScale(scaleFactorRooms, scaleFactorRooms);
    lowerEngine.setScale(scaleFactorRooms, scaleFactorRooms);
    electrical.setScale(scaleFactorRooms, scaleFactorRooms);
    storage.setScale(scaleFactorRooms, scaleFactorRooms);
    admin.setScale(scaleFactorRooms, scaleFactorRooms);
    shields.setScale(scaleFactorRooms, scaleFactorRooms);

    upperEngine.setTexture(m_roomCardTexture);
    cafeteria.setTexture(m_roomCardTexture);
    medbay.setTexture(m_roomCardTexture);
    security.setTexture(m_roomCardTexture);
    reactor.setTexture(m_roomCardTexture);
    weapons.setTexture(m_roomCardTexture);
    lowerEngine.setTexture(m_roomCardTexture);
    electrical.setTexture(m_roomCardTexture);
    storage.setTexture(m_roomCardTexture);
    admin.setTexture(m_roomCardTexture);
    shields.setTexture(m_roomCardTexture);

    upperEngine.setTextureRect(sf::IntRect(5, 7, 235, 335));
    cafeteria.setTextureRect(sf::IntRect(252, 7, 235, 335));
    medbay.setTextureRect(sf::IntRect(500, 8, 236, 337));
    security.setTextureRect(sf::IntRect(746, 8, 235, 335));
    reactor.setTextureRect(sf::IntRect(997, 8, 235, 335));
    weapons.setTextureRect(sf::IntRect(1259, 8, 235, 335));
    lowerEngine.setTextureRect(sf::IntRect(5, 371, 235, 335));
    electrical.setTextureRect(sf::IntRect(252, 371, 235, 335));
    storage.setTextureRect(sf::IntRect(501, 370, 235, 335));
    admin.setTextureRect(sf::IntRect(746, 370, 235, 335));
    shields.setTextureRect(sf::IntRect(995, 371, 235, 335));

    m_cardList.push_back(new Card("roomCard", "upperEngine", m_roomCardTexture, upperEngine));
    m_cardList.push_back(new Card("roomCard", "cafeteria", m_roomCardTexture, cafeteria));
    m_cardList.push_back(new Card("roomCard", "medbay", m_roomCardTexture, medbay));
    m_cardList.push_back(new Card("roomCard", "security", m_roomCardTexture, security));
    m_cardList.push_back(new Card("roomCard", "reactor", m_roomCardTexture, reactor));
    m_cardList.push_back(new Card("roomCard", "weapons", m_roomCardTexture, weapons));
    m_cardList.push_back(new Card("roomCard", "lowerEngine", m_roomCardTexture, lowerEngine));
    m_cardList.push_back(new Card("roomCard", "electrical", m_roomCardTexture, electrical));
    m_cardList.push_back(new Card("roomCard", "storage", m_roomCardTexture, storage));
    m_cardList.push_back(new Card("roomCard", "admin", m_roomCardTexture, admin));
    m_cardList.push_back(new Card("roomCard", "shields", m_roomCardTexture, shields));


    /// Définition des cartes armes (11 à 16)

    float scaleFactorWeapons = 0.5;

    sf::Sprite tuyau;
    sf::Sprite couteau;
    sf::Sprite cle;
    sf::Sprite marteau;
    sf::Sprite matraque;
    sf::Sprite pistolet;

    tuyau.setTexture(m_weaponCardTexture);
    couteau.setTexture(m_weaponCardTexture);
    cle.setTexture(m_weaponCardTexture);
    marteau.setTexture(m_weaponCardTexture);
    matraque.setTexture(m_weaponCardTexture);
    pistolet.setTexture(m_weaponCardTexture);

    tuyau.setScale(scaleFactorRooms, scaleFactorWeapons);
    couteau.setScale(scaleFactorRooms, scaleFactorWeapons);
    cle.setScale(scaleFactorRooms, scaleFactorWeapons);
    marteau.setScale(scaleFactorRooms, scaleFactorWeapons);
    matraque.setScale(scaleFactorRooms, scaleFactorWeapons);
    pistolet.setScale(scaleFactorRooms, scaleFactorWeapons);


    tuyau.setTextureRect(sf::IntRect(5, 7, 225, 322));
    couteau.setTextureRect(sf::IntRect(250, 7, 223, 321));
    pistolet.setTextureRect(sf::IntRect(492, 7, 222, 321));
    cle.setTextureRect(sf::IntRect(732, 7, 225, 322));
    marteau.setTextureRect(sf::IntRect(6, 333, 224, 322));
    matraque.setTextureRect(sf::IntRect(249, 333, 224, 322));


    m_cardList.push_back(new Card("weaponCard", "tuyau", m_weaponCardTexture, tuyau));
    m_cardList.push_back(new Card("weaponCard", "couteau", m_weaponCardTexture, couteau));
    m_cardList.push_back(new Card("weaponCard", "pistolet", m_weaponCardTexture, pistolet));
    m_cardList.push_back(new Card("weaponCard", "cle", m_weaponCardTexture, cle));
    m_cardList.push_back(new Card("weaponCard", "marteau", m_weaponCardTexture, marteau));
    m_cardList.push_back(new Card("weaponCard", "matraque", m_weaponCardTexture, matraque));



    /// Définition des cartes joueurs (17 à 25)

    float scaleFactorPlayers = 0.6;

    sf::Sprite redSkin;
    sf::Sprite orangeSkin;
    sf::Sprite yellowSkin;
    sf::Sprite lightgreenSkin;
    sf::Sprite greenSkin;
    sf::Sprite cyanSkin;
    sf::Sprite blueSkin;
    sf::Sprite whiteSkin;
    sf::Sprite purpleSkin;

    redSkin.setTexture(m_playerCardTexture);
    orangeSkin.setTexture(m_playerCardTexture);
    yellowSkin.setTexture(m_playerCardTexture);
    lightgreenSkin.setTexture(m_playerCardTexture);
    greenSkin.setTexture(m_playerCardTexture);
    cyanSkin.setTexture(m_playerCardTexture);
    blueSkin.setTexture(m_playerCardTexture);
    purpleSkin.setTexture(m_playerCardTexture);
    whiteSkin.setTexture(m_playerCardTexture);

    redSkin.setScale(scaleFactorPlayers, scaleFactorPlayers);
    orangeSkin.setScale(scaleFactorPlayers, scaleFactorPlayers);
    yellowSkin.setScale(scaleFactorPlayers, scaleFactorPlayers);
    lightgreenSkin.setScale(scaleFactorPlayers, scaleFactorPlayers);
    greenSkin.setScale(scaleFactorPlayers, scaleFactorPlayers);
    cyanSkin.setScale(scaleFactorPlayers, scaleFactorPlayers);
    blueSkin.setScale(scaleFactorPlayers, scaleFactorPlayers);
    purpleSkin.setScale(scaleFactorPlayers, scaleFactorPlayers);
    whiteSkin.setScale(scaleFactorPlayers, scaleFactorPlayers);


    redSkin.setTextureRect(sf::IntRect(93, 7, 197, 276));
    whiteSkin.setTextureRect(sf::IntRect(300, 7, 197, 276));
    lightgreenSkin.setTextureRect(sf::IntRect(508, 7, 197, 276));
    orangeSkin.setTextureRect(sf::IntRect(715, 7, 197, 276));
    cyanSkin.setTextureRect(sf::IntRect(922, 7, 197, 276));
    greenSkin.setTextureRect(sf::IntRect(300, 354, 197, 276));
    yellowSkin.setTextureRect(sf::IntRect(508, 354, 197, 276));
    blueSkin.setTextureRect(sf::IntRect(715, 354, 197, 276));
    purpleSkin.setTextureRect(sf::IntRect(922, 354, 196, 276));


    m_cardList.push_back(new Card("playerCard", "redSkin", m_playerCardTexture, redSkin));
    m_cardList.push_back(new Card("playerCard", "whiteSkin", m_playerCardTexture, whiteSkin));
    m_cardList.push_back(new Card("playerCard", "lightgreenSkin", m_playerCardTexture, lightgreenSkin));
    m_cardList.push_back(new Card("playerCard", "orangeSkin", m_playerCardTexture, orangeSkin));
    m_cardList.push_back(new Card("playerCard", "cyanSkin", m_playerCardTexture, cyanSkin));
    m_cardList.push_back(new Card("playerCard", "greenSkin", m_playerCardTexture, greenSkin));
    m_cardList.push_back(new Card("playerCard", "yellowSkin", m_playerCardTexture, yellowSkin));
    m_cardList.push_back(new Card("playerCard", "blueSkin", m_playerCardTexture, blueSkin));
    m_cardList.push_back(new Card("playerCard", "purpleSkin", m_playerCardTexture, purpleSkin));

    cout << "[SUCCES] : Affectation de tous les sprites des elements du jeu. \n\n";

    m_originalCardsList = m_cardList;

    cout << "[SUCCES] : Copie du deck original avant melange effectue. " << m_cardList.size() << " cartes copiees dans m_originalCardsList de la classe Enveloppe.\n\n";
}

void Envelope::shuffleEnvelope() {

    ///****************************************************************************************************//
    /// La fonction ci-dessous permet de mélanger les cartes du jeu                                        //
    ///****************************************************************************************************//

    cout << "[DEBUG] Taille paquet avant melange : " << m_cardList.size() << "\n\n";

    std::random_shuffle(m_cardList.begin(), m_cardList.end());

    cout << "[DEBUG] Taille paquet apres melange : " << m_cardList.size() << "\n\n";
}

void Envelope::fillDeck(vector<Player>& playerList, int nbPlayer) {

    ///****************************************************************************************************//
    /// Permet de générer une suite de carte consituant un deck                                            //
    /// ATTENTION : les cartes retournées seront définitivement perdues si non récupérées !                //
    ///****************************************************************************************************//

    cout << "[DEBUG] Taille paquet avant distribution : " << m_cardList.size() << "\n\n";
    cout << "[DEBUG] Contenu du paquet avant distribution : \n";

    for (int i = 0; i <= m_cardList.size() -1; i ++) {
        cout << m_cardList[i]->getAttribut() << " + ";
    }
    cout << "\n\n";


    while (m_cardList.size() > 0) {            //  Vérification qu'il reste des cartes après la boucle for

        for (int i = 0; i != nbPlayer; i++) {

            if (m_cardList.size() > 0) {       // Vérification qu'il reste des cartes à distribuer

                // On insère dans le joueur la toute dernière case du tableau de carte.
                // Pour rappel, ce tableau a déjà été mélanger dans le cluedo.cpp

                playerList[i].addToDeck(m_cardList[m_cardList.size() - 1]);
                m_cardList.pop_back();              // On retire ensuite la dernière case du tableau, c'est à dire celle qui a été insérée

            }
        }
    }
    cout << "[DEBUG] Taille paquet apres distribution : " << m_cardList.size() << "\n\n";

}



vector<Card *> Envelope::generateSolution() {

    ///****************************************************************************************************//
    /// Permet de générer une suite de carte consituant une solution                                        //
    /// ATTENTION : les cartes retournées seront définitivement perdues si non récupérées !                //
    ///****************************************************************************************************//


    vector<Card *> temp;

    cout << "Taille paquet avant creation des solutions : " << m_cardList.size() << "\n\n";

    int tempIterator = -1;

    for (int i = 0; i <= m_cardList.size() -1 ; i ++){
        if (m_cardList[i]->getType() == "weaponCard") {
            tempIterator = i;
            break;
        }
    }

    temp.push_back(m_cardList[tempIterator]);
    m_cardList.erase(m_cardList.begin() + tempIterator );
    tempIterator = -1;

    for (int j = 0; j <= m_cardList.size() -1 ; j ++){
        if (m_cardList[j]->getType() == "roomCard") {
            tempIterator = j;
            break;
        }
    }

    temp.push_back(m_cardList[tempIterator]);
    m_cardList.erase(m_cardList.begin() + tempIterator );
    tempIterator = -1;

    for (int z = 0; z <= m_cardList.size() -1 ; z ++){
        if (m_cardList[z]->getType() == "playerCard") {
            tempIterator = z;
            break;
        }
    }

    temp.push_back(m_cardList[tempIterator]);
    m_cardList.erase(m_cardList.begin() + tempIterator );
    tempIterator = -1;

    cout << "Taille paquet après generation solution : "<< m_cardList.size() << "\n\n";
    // Envoie des solutions en console.
    cout << "[SOLUTION DU JEU - DEBUG ONLY]\n";
    for (int i = 0; i <= 2; i++) {
        cout << " La carte " << temp[i]->getAttribut() << " est solution du jeu.\n" ;
    }
    cout << "\n";

    return temp;

}


void Envelope::displayThisCard(int i, sf::RenderWindow *window) {

    ///****************************************************************************************************//
    /// Cette fonction permet d'afficher une carte en particulier à un endroit de l'égran.                 //
    ///****************************************************************************************************//

    m_cardList[i]->display(width / 2, height / 2, window);
}


///------------------------------------------ Getter et accesseurs -------------------------------------///

vector<Card *> Envelope::getCardList() {
    return m_cardList;
};

vector<Card*> Envelope::getOriginalCardsList() {
    return m_originalCardsList;
}

vector<Card*> Envelope::getPlayersCardsList() {

    vector<Card*> temp;

    for (int i = 0; i != m_originalCardsList.size() -1; i++) {
        if (m_originalCardsList[i]->getType() == "playerCard" ) {
            temp.push_back(m_originalCardsList[i]);
        }
    }
    return temp;
}

vector<Card*> Envelope::getWeaponsCardsList() {

    vector<Card*> temp;

    for (int i = 0; i != m_originalCardsList.size() -1; i++) {
        if (m_originalCardsList[i]->getType() == "weaponCard" ) {
            temp.push_back(m_originalCardsList[i]);
        }
    }
    return temp;
}

vector<Card*> Envelope::getRoomsCardsList() {

    vector<Card*> temp;

    for (int i = 0; i != m_originalCardsList.size() -1; i++) {
        if (m_originalCardsList[i]->getType() == "roomCard" ) {
            temp.push_back(m_originalCardsList[i]);
        }
    }
    return temp;
}



