#include "../HEADER/cluedo.h"

///******************************************* CONSTRUCTEUR PRINCIPAL *********************************************************************//

Cluedo::Cluedo() {

    // Fenêtre d'affichage :


    sf::Image whoIsIcon;
    whoIsIcon.loadFromFile("../DATA/SkinPlayer/skin9.png");
    m_window.create(sf::VideoMode(width, height, 32), "WhoIs", sf::Style::Close);
    m_window.setIcon(whoIsIcon.getSize().x, whoIsIcon.getSize().y, whoIsIcon.getPixelsPtr());
    m_window.setFramerateLimit(60);

    // Dés :

    m_gameDices = new Dices(&m_window);

    // Valeurs par défauts nécessaires au lancement du jeu

    m_currentSelectedPlayer = -1;

    m_actualMenu = 0;

    m_turn = 0;

    m_nbPlayers = 3;

    m_nbenteredPassword = 0;

    // Différents menus :

    Menu *menuHome = new Menu("../DATA/Others/backgroundHome.jpg");
    Menu *menuPlayerChoice = new Menu("../DATA/Others/backgroundHome.jpg");
    Menu *menuPseudo = new Menu("../DATA/Others/backgroundHome.jpg");
    Menu *menuGame = new Menu();
    Menu *menuHypothesis = new Menu("../DATA/Others/backgroundHypothese.jpg");
    Menu *menuVerifyHypothesis = new Menu("../DATA/Others/backgroundVerify.jpg");
    Menu *menuDefeat = new Menu("../DATA/Others/backgroundDefeat.jpg");
    Menu *menuPassword = new Menu("../DATA/Others/backgroundHome.jpg");
    Menu *menuWin = new Menu("../DATA/Others/backgroundWin.jpg");


    m_menus.push_back(menuHome);
    m_menus.push_back(menuPlayerChoice);
    m_menus.push_back(menuPseudo);
    m_menus.push_back(menuGame);
    m_menus.push_back(menuHypothesis);
    m_menus.push_back(menuVerifyHypothesis);
    m_menus.push_back(menuDefeat);
    m_menus.push_back(menuPassword);
    m_menus.push_back(menuWin);


    // Cartes du jeu :

    Envelope *newEnvelope = new Envelope();
    m_gameCards = newEnvelope;

    // Initialisation

    initButtons();

    // Démarrage de la bande sonore du jeu :

    if (!m_music.openFromFile("../DATA/Sound/soundtrack.ogg")) cerr;
    else {
        m_music.play();
        m_music.setLoop(true);
    }
}
///*************************************************************************************************************************//


void Cluedo::nextTurn() {

    ///**************************************************************************************************//
    /// Cette fonction permet de passer au tour suivant, et de préparer ce dernier                       //
    ///**************************************************************************************************//

    // Avant de terminé le tour de ce joueur, on remet à 0 ses valeurs pour le prochain tour
    m_playerList[m_turn].setWalkPower(0);
    m_playerList[m_turn].setHasLaunched(false);

    // Vérification de sûreté :
    int NbPlayerAlive = 0;

    for (int i = 0; i <= m_playerList.size() -1; i++) {
        if (m_playerList[i].getIsDead() == false) {
            NbPlayerAlive++;
        }
    }
    if (NbPlayerAlive < 2) {
        m_actualMenu = 8;
    }
    else {  // Changement de la variable :
        do {
            m_turn++;
            if (m_turn == m_nbPlayers) {
                m_turn = 0;
            }
        }while(m_playerList[m_turn].getIsDead() == true);
    }
}


void Cluedo::initCard() {

    ///**************************************************************************************************//
    /// Initialisation de tout ce qui est lié aux cartes du jeu. Inclus les decks et cartes solutions    //
    ///**************************************************************************************************//

    m_gameCards->fillEnvelope();                                                        // Load les cartes de jeu
    m_originalGameCards = m_gameCards;                                                  // Récupère les cartes de jeu originales
    m_gameCards->shuffleEnvelope();                                                     // Mélange
    m_solution = m_gameCards->generateSolution();                                        // Génére une solution
    m_gameCards->fillDeck(m_playerList, m_nbPlayers);                                  // Remplie les decks des joueurs
}


void Cluedo::initPlayer() {

    ///**************************************************************************************************//
    /// Initialisation des joueurs et de leurs donnés respectives                                        //
    ///**************************************************************************************************//
    std::vector<int> alreadyUsedSkin(9);

    for (int i = 0; i < m_nbPlayers; ++i) {
        int temp = util::random(1, 9);
        std::string path = "../DATA/SkinPlayer/skin";

        while (util::intIsPresentIn(temp, alreadyUsedSkin)) {
            temp = util::random(1, 9);
        }


        alreadyUsedSkin[i] = temp;
        path += std::to_string(temp);
        path += ".png";


        m_playerList.push_back({9, 4, m_menus[2]->getButtonText(i + 1), m_menus[7]->getButtonText(i + 1), path});
    }

}

void Cluedo::initHypothesis(bool isAccusing) {


    m_hypothesisModule = new HypothesisModule(m_playerList, m_turn, m_solution, isAccusing);
    m_hypothesisModule->copyOriginalCards(m_originalGameCards->getOriginalCardsList());
    m_hypothesisModule->searchNumRoom(m_board.getRoomHere(m_playerList[m_turn].getX(), m_playerList[m_turn].getY()));
}


bool Cluedo::isRunning() {

    ///**************************************************************************************************//
    /// La fonction ci-dessous permet de charger tous les boutons du jeu. Chaque bouton est lié à un menu//
    ///**************************************************************************************************//

    return m_window.isOpen();
}


void Cluedo::initButtons() {

    sf::Color dependColor(96, 96, 96);

    ///**************************************************************************************************//
    /// La fonction ci-dessous permet de charger tous les boutons du jeu. Chaque bouton est lié à un menu//
    ///**************************************************************************************************//

    // Home page :

    m_menus[0]->addButtons(2 * width / 20, 2 * height / 20, 16 * width / 20, 6 * height / 20,
                           sf::Color(0, 0, 0, 150), "Who Is?", false,
                           "../DATA/Fonts/CottonButter.ttf", false);
    m_menus[0]->addButtons(5 * width / 20, 10 * height / 20, 10 * width / 20, 3 * height / 20,
                           sf::Color(0, 0, 0, 150), "creer des comptes", true);
    m_menus[0]->addButtons(5 * width / 20, 14 * height / 20, 10 * width / 20, 3 * height / 20,
                           sf::Color(0, 0, 0, 150), "Quitter le jeu", true);

    // Page de séléction du nombre de joueur :

    m_menus[1]->addButtons(3 * width / 20, 2 * height / 20, 14 * width / 20, height * 0.2,
                           sf::Color(255,255,255,100
                           ), "Nombre de joueurs", false);

    m_menus[1]->addButtons(5 * width / 20, 8 * height / 20, 10 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "3", true);
    m_menus[1]->addButtons(5 * width / 20, 11 * height / 20, 10 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "4", true);
    m_menus[1]->addButtons(5 * width / 20, 14 * height / 20, 10 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "5", true);
    m_menus[1]->addButtons(5 * width / 20, 17 * height / 20, 10 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "6", true);

    // Page de séléction des pseudos :

    m_menus[2]->addButtons(3 * width / 20, 1 * height / 20, 14 * width / 20, 3 * height / 20,
                           sf::Color(255,255,255,50), "Identifiants", false);

    m_menus[2]->addButtons(2 * width / 20, 6 * height / 20, 7 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "Joueur 1: ", true);
    m_menus[2]->addButtons(2 * width / 20, 9 * height / 20, 7 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "Joueur 2: ", true);
    m_menus[2]->addButtons(2 * width / 20, 12 * height / 20, 7 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "Joueur 3: ", true);
    m_menus[2]->addButtons(11 * width / 20, 6 * height / 20, 7 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "Joueur 4: ", true);
    m_menus[2]->addButtons(11 * width / 20, 9 * height / 20, 7 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "Joueur 5: ", true);
    m_menus[2]->addButtons(11 * width / 20, 12 * height / 20, 7 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "Joueur 6: ", true);

    m_menus[2]->addButtons(2 * width / 20, 17 * height / 20, 7 * width / 20, height / 20,
                           sf::Color(195, 77, 77, 200), "Retour", true);
    m_menus[2]->addButtons(11 * width / 20, 17 * height / 20, 7 * width / 20, height / 20,
                           sf::Color(51, 153, 51, 200), "Definir des mots de passes", true);


    // Page de partie

    m_menus[3]->addButtons(m_gameDices->getPos1X(), m_gameDices->getPos1Y(), 200, 75, sf::Color::Transparent, "",
                           true, "../DATA/Fonts/In your face, joffrey!.ttf", false); // Zone de dés cliquable.
    m_menus[3]->addButtons(width * 0.04, height * 0.92, width / 5, height * 0.05, sf::Color::White, "Tour suivant",
                           true, "../DATA/Fonts/In your face, joffrey!.ttf", true);
    m_menus[3]->addButtons(width * 0.40, height * 0.92, width / 5, height * 0.05, dependColor, "Faire hypothese",
                           true, "../DATA/Fonts/In your face, joffrey!.ttf", true);
    m_menus[3]->addButtons(width * 0.75, height * 0.92, width / 5, height * 0.05, dependColor, "Faire accusation",
                           true, "../DATA/Fonts/In your face, joffrey!.ttf", true);

    // Hypothese

    m_menus[4]->addButtons(1 * width / 16, 2 * height / 18, 4 * width / 16, 2 * height / 18,
                           sf::Color(0, 0, 0, 150),
                           "Suivant",
                           true, "../DATA/Fonts/In your face, joffrey!.ttf", true);
    m_menus[4]->addButtons(6 * width / 16, 2 * height / 18, 4 * width / 16, 2 * height / 18,
                           sf::Color(0, 0, 0, 150),
                           "Suivant",
                           true, "../DATA/Fonts/In your face, joffrey!.ttf", true);
    m_menus[4]->addButtons(11 * width / 16, 2 * height / 18, 4 * width / 16, 2 * height / 18,
                           sf::Color(0, 0, 0, 150),
                           "Lieu",
                           false, "../DATA/Fonts/In your face, joffrey!.ttf", true);
    m_menus[4]->addButtons(1 * width / 16, 14 * height / 18, 4 * width / 16, 2 * height / 18,
                           sf::Color(0, 0, 0, 150),
                           "Precedent",
                           true, "../DATA/Fonts/In your face, joffrey!.ttf", true);
    m_menus[4]->addButtons(6 * width / 16, 14 * height / 18, 4 * width / 16, 2 * height / 18,
                           sf::Color(0, 0, 0, 150),
                           "Precedent",
                           true, "../DATA/Fonts/In your face, joffrey!.ttf", true);
    m_menus[4]->addButtons(11 * width / 16, 14 * height / 18, 4 * width / 16, 2 * height / 18,
                           sf::Color(56, 209, 76, 150),
                           "Valider",
                           true, "../DATA/Fonts/In your face, joffrey!.ttf", true);
    m_menus[4]->addButtons(6 * width / 16, height * 0.93, 4 * width / 16, height * 0.05,
                           sf::Color(255, 0, 0, 150),
                           "Retour",
                           true, "../DATA/Fonts/In your face, joffrey!.ttf", true);

    // Vérification hypothèse :

    m_menus[5]->addButtons(width * 0.10, height * 0.08, width * 0.80, height * 0.10,
                           sf::Color(0, 0, 0, 150),
                           "Resultat de votre hypothese :",
                           false);

    m_menus[5]->addButtons(width * 0.3, height * 0.20, width * 0.40, height * 0.10,
                           sf::Color(0, 0, 0, 150),
                           " ",
                           true, "../DATA/Fonts/In your face, joffrey!.ttf", false);
    m_menus[5]->addButtons(width * 0.4, height * 0.75, width * 0.20, height * 0.10,
                           sf::Color(0, 0, 0, 150),
                           " ",
                           false, "../DATA/Fonts/In your face, joffrey!.ttf", false);

    m_menus[5]->addButtons(width * 0.30, height * 0.88, width * 0.40, height * 0.1,
                           sf::Color(255, 0, 0, 150),
                           "Retour au jeu",
                           true, "../DATA/Fonts/In your face, joffrey!.ttf", true);


    // Accusation fausse : défaite

    m_menus[6]->addButtons(width * 0.30, height * 0.03, width * 0.40, height * 0.10,
                           sf::Color(0, 0, 0, 150),
                           "Vous etes mort...",
                           false);
    m_menus[6]->addButtons(width * 0.30, height * 0.165
                           , width * 0.40, height * 0.05,
                           sf::Color(96, 96, 96, 200),
                           "Solution du jeu :",
                           false);
    m_menus[6]->addButtons(width * 0.40, height * 0.85, width * 0.20, height * 0.10,
                           sf::Color(255, 0, 0, 150),
                           "Spectateur",
                           true, "../DATA/Fonts/In your face, joffrey!.ttf", true);

    // Vérification mot de passe :

    m_menus[7]->addButtons(3 * width / 20, 1 * height / 20, 14 * width / 20, 3 * height / 20,
                           sf::Color(255,255,255,100), "Mots de Passe", false);

    m_menus[7]->addButtons(2 * width / 20, 6 * height / 20, 7 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "", true);
    m_menus[7]->addButtons(2 * width / 20, 9 * height / 20, 7 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "", true);
    m_menus[7]->addButtons(2 * width / 20, 12 * height / 20, 7 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "", true);
    m_menus[7]->addButtons(11 * width / 20, 6 * height / 20, 7 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "", true);
    m_menus[7]->addButtons(11 * width / 20, 9 * height / 20, 7 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "", true);
    m_menus[7]->addButtons(11 * width / 20, 12 * height / 20, 7 * width / 20, 2 * height / 20,
                           sf::Color(0, 0, 0, 150), "", true);

    m_menus[7]->addButtons(2 * width / 20, 17 * height / 20, 7 * width / 20, height / 20,
                           sf::Color(195, 77, 77, 200), "Retour", true);
    m_menus[7]->addButtons(11 * width / 20, 17 * height / 20, 7 * width / 20, height / 20,
                           sf::Color(51, 153, 51, 200), "Connexion a WhoIs", true);

    // Victoire du joueur

    m_menus[8]->addButtons(width * 0.10, height * 0.08, width * 0.80, height * 0.10,
                           sf::Color(0, 0, 0, 150), "Parie terminee : victoire de", true);
    m_menus[8]->addButtons(width* 0.30, height * 0.8150, width * 0.40, height * 0.10,
                           sf::Color(0, 0, 0, 150),
                           "     " , true);

}




void Cluedo::handleEvents() {

    ///**************************************************************************************************//
    /// Cette fonction permet de gérer les évenement liés au jeu                                         //
    ///**************************************************************************************************//


    sf::Event event{};

    while (m_window.pollEvent(event)) {

        switch (event.type) {

            case sf::Event::Closed:
                m_window.close();
                break;

            case sf::Event::TextEntered:
                if (event.text.unicode != 8) m_inputText += event.text.unicode;
                else m_inputText.pop_back();
                break;

            case sf::Event::KeyPressed:
                m_keyPressedCode = event.key.code;
                if (m_actualMenu == 3) {
                    if (m_keyPressedCode <= 74 && m_keyPressedCode >= 71) movePlayer(m_playerList[m_turn]);
                }
                break;

            case sf::Event::MouseButtonPressed:
                m_menus[m_actualMenu]->sendClick(true);
                break;

            case sf::Event::MouseButtonReleased:
                m_menus[m_actualMenu]->sendClick(false);
                break;

            case sf::Event::MouseMoved:
                m_menus[m_actualMenu]->sendMousePos(sf::Mouse::getPosition(m_window));
                break;
        }
    }
}

void Cluedo::movePlayer(Player &p) {

    ///**************************************************************************************************//
    /// Cette fonction permet de déplacer un joueur sur le plateau                                       //
    ///**************************************************************************************************//


    int x = p.getX();
    int y = p.getY();
    Cell *currentCell = m_board.getCell(x, y);

    if (p.getWalkPower() > 0) {

        if (currentCell->getIsDoor()) {
            bool hasMoved = false;
            std::vector<Cell *> otherDoors = m_board.getOtherDoors(currentCell->getType());

            for (int i = 0; i < otherDoors.size(); ++i) {
                if (!hasMoved) {
                    int otherX = util::map(otherDoors[i]->getX(), margin / 2,
                                           (m_board.getCols() - 1) * m_board.getCellWidht() + margin / 2, 0,
                                           m_board.getCols());
                    int otherY = util::map(otherDoors[i]->getY(), margin / 2,
                                           (m_board.getRows() - 1) * m_board.getCellHeight() + margin / 2, 0,
                                           m_board.getRows());

                    Cell *otherDoorUp = m_board.getCell(otherX, otherY - 1);
                    Cell *otherDoorRight = m_board.getCell(otherX + 1, otherY);
                    Cell *otherDoorDown = m_board.getCell(otherX, otherY + 1);
                    Cell *otherDoorLeft = m_board.getCell(otherX - 1, otherY);

                    int otherDoorType = otherDoors[i]->getType();

                    if (otherDoors[i]->isTopOpen() && m_keyPressedCode == 73 &&
                        otherDoorUp->getType() != otherDoorType)
                        p.move(otherX, otherY - 1);
                    if (otherDoors[i]->isRightOpen() && m_keyPressedCode == 72 &&
                        otherDoorRight->getType() != otherDoorType)
                        p.move(otherX + 1, otherY);
                    if (otherDoors[i]->isBottomOpen() && m_keyPressedCode == 74 &&
                        otherDoorDown->getType() != otherDoorType)
                        p.move(otherX, otherY + 1);
                    if (otherDoors[i]->isLeftOpen() && m_keyPressedCode == 71 &&
                        otherDoorLeft->getType() != otherDoorType)
                        p.move(otherX - 1, otherY);

                    if (p.getX() != x || p.getY() != y) {
                        hasMoved = true;
                        p.setWalkPower(p.getWalkPower() - 1);
                    }
                }
            }

        } else {
            if (currentCell->isTopOpen() && m_keyPressedCode == 73) p.move(x, y - 1);
            if (currentCell->isRightOpen() && m_keyPressedCode == 72) p.move(x + 1, y);
            if (currentCell->isBottomOpen() && m_keyPressedCode == 74) p.move(x, y + 1);
            if (currentCell->isLeftOpen() && m_keyPressedCode == 71) p.move(x - 1, y);

            if (m_board.getCell(p.getX(), p.getY())->getIsDoor()) {
                p.setWalkPower(0);

            } else if (p.getX() != x || p.getY() != y) p.setWalkPower(p.getWalkPower() - 1);
        }
    }
}


void Cluedo::update() {

    ///*******************************************************************************************************//
    /// Gestion des évenements liés aux boutons des menus.                                                    //
    ///*******************************************************************************************************//


    switch (m_actualMenu) {

        /// Menu principale du jeu ----------------------------------------------------------------------

        case 0:

            switch (m_menus[0]->getButtonClicked()) {

                case 1: // Bouton nouvelle partie
                    m_actualMenu = 1;
                    break;

                case 2: // Bouton nouvelle partie
                    m_window.close();
                    break;
            }
            break;

            /// Menu du choix du nombre de joueurs ---------------------------------------------------------------

        case 1:

            switch (m_menus[1]->getButtonClicked()) {

                case 1: // Bouton 3 joueurs
                    m_nbPlayers = 3;
                    m_actualMenu = 2;
                    break;

                case 2: // Bouton 4 joueurs
                    m_nbPlayers = 4;
                    m_actualMenu = 2;
                    break;

                case 3: // Bouton 5 joueurs
                    m_nbPlayers = 5;
                    m_actualMenu = 2;
                    break;

                case 4: // Bouton 6 joueurs
                    m_nbPlayers = 6;
                    m_actualMenu = 2;
                    break;
            }
            break;

            /// Menu permettant de définir les noms des joueurs  --------------------------------------------------

        case 2:

            switch (m_menus[2]->getButtonClicked()) {

                case 1: // Saisie joueur 1
                    m_currentSelectedPlayer = 1;
                    m_inputText = "";
                    break;
                case 2: // Saisie joueur 2
                    m_currentSelectedPlayer = 2;
                    m_inputText = "";
                    break;
                case 3: // Saisie joueur 3
                    m_currentSelectedPlayer = 3;
                    m_inputText = "";
                    break;
                case 4: // Saisie joueur 4
                    m_currentSelectedPlayer = 4;
                    m_inputText = "";
                    break;
                case 5: // Saisie joueur 4
                    m_currentSelectedPlayer = 5;
                    m_inputText = "";
                    break;
                case 6: // Saisie joueur 4
                    m_currentSelectedPlayer = 6;
                    m_inputText = "";
                    break;
                case 7: // Bouton back
                    m_actualMenu = 1;
                    m_currentSelectedPlayer = -1;
                    m_inputText = "";
                    break;
                case 8: // Bouton next --> Lance la partie
                    m_inputText = "";
                    m_currentSelectedPlayer = -1;
                    m_actualMenu = 7;
                    break;

                default:
                    if (m_inputText.length() < 20 && m_inputText.length() >= 0)
                        m_menus[2]->setButtonText(m_currentSelectedPlayer, m_inputText);
                    break;
            }
            break;

            /// Menu correspondant à la partie en cours (plateau, deck...) ---------------------------------------------------------------

        case 3:

            m_menus[3]->initFont("../DATA/Fonts/In your face, joffrey!.ttf", "../DATA/Fonts/CottonButter.ttf");

            switch (m_menus[3]->getButtonClicked()) {

                case 0: // Bouton lancer les dés

                    if (m_playerList[m_turn].getHasLaunched() == false) {
                        m_gameDices->lancer(&m_window);
                        m_playerList[m_turn].setWalkPower(m_gameDices->getResultat());
                        m_playerList[m_turn].setHasLaunched(true);
                    }
                    break;

                case 1: // Bouton next turn
                    nextTurn();
                    break;

                case 2: // Bouton hypothèse

                    initHypothesis(false); // False car le joueur n'accuse pas
                    m_actualMenu = 4;
                    break;

                case 3: // Bouton accusation
                    initHypothesis(true); // True car le joueur accuse
                    m_actualMenu = 4;
                    break;
            }

            break;

            /// Menu correspondant à la création d'hypothèse ---------------------------------------------------------

        case 4:
            switch (m_menus[4]->getButtonClicked()) {

                case 0: // Next weapon
                    m_hypothesisModule->nextWeaponIterator();
                    break;

                case 1: // Next player
                    m_hypothesisModule->backPlayerIterator();
                    break;

                case 3: // Back weapon
                    m_hypothesisModule->backWeaponIterator();
                    break;

                case 4: // Back player
                    m_hypothesisModule->nextPlayerIterator();
                    break;

                case 5: // Valider
                    m_hypothesisModule->createHypothesis();
                    m_hypothesisModule->verifyHypothesis();

                    if (m_hypothesisModule->checkIfAccusing() == false) {
                        m_actualMenu = 5;
                    } else {
                        if(m_hypothesisModule->verifySolution() == true) { // Si l'accusation est avérée, le joueur gagne
                            m_actualMenu = 8;
                        }
                        else {                          // Sinon il perd
                            m_actualMenu = 6;
                        }
                    }
                    break;
                case 6: // Retour
                    m_actualMenu = 3;
                    m_hypothesisModule->~HypothesisModule();
                    m_hypothesisModule = nullptr;
                    break;
            }
            break;

            /// Menu correspondant à la vérification de l'hypothèse --------------------------
        case 5 :
            switch (m_menus[5]->getButtonClicked()) {

                case 3: // Retour plateau
                    m_actualMenu = 3;
                    nextTurn();
                    break;
            }

            break;

            /// Menu correspondant à la défaite d'un joueur --------------------------
        case 6:

            switch (m_menus[6]->getButtonClicked()) {

                case 2: // Retour plateau
                    m_actualMenu = 3;
                    m_playerList[m_turn].kill();
                    nextTurn();
                    break;
            }

            /// Menu correspondant à la saisie des mots de passe --------------------------
        case 7:

            switch (m_menus[7]->getButtonClicked()) {

                case 1: // Saisie joueur 1
                    m_currentSelectedPlayer = 1;
                    m_inputText = "";
                    break;
                case 2: // Saisie joueur 2
                    m_currentSelectedPlayer = 2;
                    m_inputText = "";
                    break;
                case 3: // Saisie joueur 3
                    m_currentSelectedPlayer = 3;
                    m_inputText = "";
                    break;
                case 4: // Saisie joueur 4
                    m_currentSelectedPlayer = 4;
                    m_inputText = "";
                    break;
                case 5: // Saisie joueur 4
                    m_currentSelectedPlayer = 5;
                    m_inputText = "";
                    break;
                case 6: // Saisie joueur 4
                    m_currentSelectedPlayer = 6;
                    m_inputText = "";
                    break;
                case 7: // Bouton back
                    m_actualMenu = 2;
                    m_currentSelectedPlayer = -1;
                    m_inputText = "";
                    break;
                case 8: // Bouton next --> Lance la partie

                    m_nbenteredPassword = 0;

                    for (int i = 0; i < m_nbPlayers; ++i) {
                        m_password = m_menus[7]->getButtonText(i + 1);
                        if (m_password != "") m_nbenteredPassword++;
                    }

                    if (m_nbenteredPassword == m_nbPlayers) {
                        m_currentSelectedPlayer = -1;
                        m_inputText = "";
                        m_actualMenu = 3;

                        /// IMPORTANT : ///---------------------------

                        initPlayer();

                        m_playerList[0].move(9, 2);
                        m_playerList[1].move(26, 8);
                        m_playerList[2].move(8, 18);     //Envoi les joueurs sur les cases de départ
                        if (m_nbPlayers > 3) m_playerList[3].move(12, 2);
                        if (m_nbPlayers > 4) m_playerList[4].move(26, 11);
                        if (m_nbPlayers > 5) m_playerList[5].move(13, 18);

                        initCard();
                    }
                    break;
                default:
                    if (m_inputText.length() < 20 && m_inputText.length() >= 0)
                        m_menus[7]->setButtonText(m_currentSelectedPlayer, string(m_inputText.length(), '*'));
                    break;
            }
            break;

        case 8 :
            /// Menu Victoire d'un joueur  ---------------------------------------------------------------

            break;

    }
}


void Cluedo::display() {

    ///*****************************************************************************************************//
    ///                                       Affichage du jeu                                              //
    ///*****************************************************************************************************//

    m_window.clear(sf::Color(30, 15, 110));

    sf::Sprite skinSprite;
    sf::Texture skinTexture;
    sf::Sprite currentPlayerSkin;
    sf::Texture currentSkinTexture;

    switch (m_actualMenu) {

        /// Acceuil ------------------------------------------------------------------------------

        case 0 :

            m_menus[0]->display(&m_window);
            m_window.display();
            break;

            /// Choix nombre de joueur ------------------------------------------------------------
        case 1 :

            m_menus[1]->display(&m_window);
            m_window.display();
            break;

            /// Choix pseudos des joueurs -------------------------------------------------------------

        case 2:

            // On affiche le background :

            m_menus[2]->displayBackgroundOnly(&m_window);

            // On affichage uniquement les boutons équivalents au nombre de joueur :

            m_menus[2]->displayRestricted(0, m_nbPlayers + 1, &m_window);

            // Boutons d'actions :

            m_menus[2]->displayRestricted(7, 9, &m_window);


            // On actualise
            m_window.display();

            break;

            /// Partie de Cluedo en cours -------------------------------------------------------------

        case 3:

            // Debug, voir librairies.h

            if (ENABLEDEBUG == 1) {
                m_playerList[m_turn].setWalkPower(999);
            }


            // Affichage élément des éléments de contexte

            m_board.display(&m_window);                         // Affichage plateau
            m_gameDices->displayDices(&m_window);               // Affichage dés
            m_menus[3]->displayTurnInfo(m_playerList[m_turn], &m_window);  // Affiche des infos du tour

            // Affiche le skin du joueur qui joue

            currentSkinTexture.loadFromFile(m_playerList[m_turn].getSkin());
            currentPlayerSkin.setTexture(currentSkinTexture);
            currentPlayerSkin.setPosition(width * 0.05f, height * 0.01);
            currentPlayerSkin.setScale(0.25f, 0.25f);
            m_window.draw(currentPlayerSkin);

            // Affichage des boutons d'action

            if (m_board.getCell(m_playerList[m_turn].getX(), m_playerList[m_turn].getY())->getIsDoor() == true) {

                // Les boutons sont cliquables et colorés en blanc uniquement si le joueur est sur une porte
                m_menus[3]->changeButtonsColor(2, sf::Color::White);
                m_menus[3]->changeButtonsColor(3, sf::Color::White);
                m_menus[3]->changeButtonsClickable(2, true);
                m_menus[3]->changeButtonsClickable(3, true);
            } else {
                // Sinon ils sont gris
                m_menus[3]->changeButtonsColor(2, sf::Color(96, 96, 96));
                m_menus[3]->changeButtonsColor(3, sf::Color(96, 96, 96));
                m_menus[3]->changeButtonsClickable(2, false);
                m_menus[3]->changeButtonsClickable(3, false);
            }

            // Affichage du menu et bouton

            m_menus[3]->display(&m_window);

            // Affichage des joueurs sur le plateau

            for (int i = 0; i != m_nbPlayers; i++) {
                if (m_playerList[i].getIsDead() == false) {
                    m_playerList[i].display(&m_window, m_board.getCellWidht(), m_board.getCellHeight());
                }
            }

            // Affichage du deck des joueurs

            m_playerList[m_turn].displayDeck(&m_window);

            // Actualisation de l'affichage

            m_window.display();

            break;

            ///  Menu de formulation des hypothèses --------------------------------------------------------------------------

        case 4:

            m_menus[4]->display(&m_window);
            m_hypothesisModule->displayChoice(&m_window);
            m_window.display();
            break;

            ///  Menu de résutat des hypotyhèses --------------------------------------------------------------------------

        case 5:
            m_menus[5]->display(&m_window);
            m_hypothesisModule->displayHypothesis(&m_window);
            m_window.display();
            break;

            ///  Menu de défaite d'un joueur --------------------------------------------------------------------------

        case 6:
            m_menus[6]->display(&m_window);
            m_hypothesisModule->displaySolution(&m_window);
            m_window.display();
            break;

            ///  Menu des mots de passe --------------------------------------------------------------------------

        case 7:

            // On affiche le background :

            m_menus[7]->displayBackgroundOnly(&m_window);

            // On affichage uniquement les boutons équivalents au nombre de joueur :

            m_menus[7]->displayRestricted(0, m_nbPlayers + 1, &m_window);

            // Boutons d'actions :

            m_menus[7]->displayRestricted(7, 9, &m_window);


            // On actualise
            m_window.display();
            break;

            ///  Menu en cas de victoire d'un joueur  ---------------------------------------------------------------------

        case 8:

            m_menus[8]->display(&m_window);

            skinTexture.loadFromFile(m_playerList[m_turn].getSkin());
            skinSprite.setTexture(skinTexture);
            skinSprite.setPosition(width * 0.37f, height * 0.19);
            skinSprite.setScale(1.8f, 1.8f);
            m_window.draw(skinSprite);

            m_playerList[m_turn].display(&m_window, width * 0.40f, height * 0.40f);
            util::displayText(width * 0.45, height * 0.82, 70, m_playerList[m_turn].getPseudo(), "../DATA/Fonts/In your face, joffrey!.ttf", &m_window);
            m_window.display();
            break;
    }
}