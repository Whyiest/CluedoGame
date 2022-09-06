#include "../HEADER/menu.h"
#include "../HEADER/utilitaire.h"

using namespace std;

///*************************************************************************************************************************//

Menu::Menu() = default;

Menu::Menu(std::string backgroundPath) {

    // Avec un fond
    m_backgroundTexture.loadFromImage(util::newImage(backgroundPath, width, height));
    m_backgroundTexture.setSmooth(true);
}

///*************************************************************************************************************************//


void Menu::sendMousePos(sf::Vector2<int> mousePos) {

    ///**************************************************************************************************///
    /// Cette fonction permet l'envoi de la position de la souris au programme appelant                  ///
    ///**************************************************************************************************///

    for (auto &button : m_buttons) {
        button.sendMousePos(mousePos);
    }
}

void Menu::sendClick(bool isPressed) {

    ///**************************************************************************************************///
    /// Cette fonction permet de signaler qu'un bouton du menu a été cliqué                               ///
    ///**************************************************************************************************///

    for (auto &button : m_buttons) {
        button.sendClick(isPressed);
    }
}


int Menu::getButtonClicked() {

    ///**************************************************************************************************///
    /// Cette fonction permet de trouver quel bouton du menu a été cliqué                                ///
    ///**************************************************************************************************///

    for (int i = 0; i < m_buttons.size(); ++i) { // Pour chaque bouton du menu
        if (m_buttons[i].isClicked()) return i;   // Si il est cliqué on retourne son indice
    }
    return -1;
}

void Menu::setButtonText(int index, std::string text) {
    if (index <= m_buttons.size()) m_buttons[index].setText(text);
}

std::string Menu::getButtonText(int index) {
    return m_buttons[index].getText();
}


void Menu::display(sf::RenderWindow *window) {

    ///******************************************************************************************************///
    /// Cette fonction permet d'afficher d'un coup le menu, qui pour rappel contient des boutons et un fond ///
    /// = displayRestricted de tout les boutons + displayBackground                                         ///
    ///****************************************************************************************************///

    m_backgroundSprite.setTexture(m_backgroundTexture);      // Load la texture du fond du jeu
    window->draw(m_backgroundSprite);                       // Dessine le fond du jeu

    for (auto &button : m_buttons) {                     // Pour chaque bouton lié au menu actuel
        button.display(window);                         // On l'affiche
    }
}

void Menu::addButtons(int x, int y, int w, int h, sf::Color color, std::string text, bool clickable) {

    ///**************************************************************************************************///
    /// Cette fonction permet de créé un bouton, et de relier ce dernier à un menu                       ///
    ///**************************************************************************************************///

    Button newButton = Button(x, y, w, h, color, text, clickable);
    m_buttons.push_back(newButton);
}

void Menu::addButtons(int x, int y, int w, int h, sf::Color color, std::string text, bool clickable, std::string font,
                      bool square) {

    ///**************************************************************************************************///
    /// Surcharge de la fonction ci-dessus, permet d'ajouter en plus une police et un cadre              ///
    ///**************************************************************************************************///

    Button newButton = Button(x, y, w, h, color, text, clickable);
    newButton.setFont(font);
    newButton.enableSquare(square);
    m_buttons.push_back(newButton);
}


void Menu::displayTurnInfo(Player currentplayer, sf::RenderWindow *window) {

    ///**************************************************************************************************///
    /// Permet d'afficher les informations à propos du tour actuel                                       ///
    ///**************************************************************************************************///

    // Affichage des infos sur le joueur :

    sf::Text pseudo;
    pseudo.setFont(m_titleFont);
    pseudo.setString("C'est au tour de " + currentplayer.getPseudo());
    pseudo.setCharacterSize(50);
    pseudo.setFillColor(sf::Color::White);
    pseudo.setPosition(width * 0.10, height * 0.02);
    window->draw(pseudo);

    // Affichage WalkPower

    sf::Text walkpower;
    walkpower.setFont(m_titleFont);
    walkpower.setString(to_string(currentplayer.getWalkPower()));
    walkpower.setCharacterSize(100);
    walkpower.setFillColor(sf::Color::White);
    walkpower.setPosition(width * 0.92, height * 0.72);
    window->draw(walkpower);
}

void Menu::initFont(std::string pathTitleFont, std::string pathMainFont) {

    ///**************************************************************************************************///
    /// Permet d'initialiser les polices liées au menu : celle de titre et de texte                      ///
    ///**************************************************************************************************///

    if (!m_titleFont.loadFromFile(pathTitleFont)) cerr << endl;
    if (!m_textFont.loadFromFile(pathMainFont)) cerr << endl;
}

void Menu::changeButtonsColor(int indice, sf::Color newColor) {

    ///**************************************************************************************************///
    /// Permet de changer la couleur du fond d'un bouton                                                 ///
    ///**************************************************************************************************///

    m_buttons[indice].changeColor(newColor);
};

void Menu::changeButtonsClickable(int indice, bool newBool) {

    ///**************************************************************************************************///
    /// Permet de changer le fait que le bouton soit ou non cliquable.                                   ///
    ///**************************************************************************************************///

    m_buttons[indice].changeClickable(newBool);
};

void Menu::displayRestricted(int fromThis, int toThis, sf::RenderWindow *window) {

    ///**************************************************************************************************///
    /// Fait exactement comme la fonction display mais pour un nombre restreint de bouton                ///
    ///**************************************************************************************************///

    for (int i = fromThis; i != toThis; i++) {                  // Pour chaque bouton contenu dans la range
        m_buttons[i].display(window);                         // On l'affiche
    }
}

void Menu::displayBackgroundOnly(sf::RenderWindow *window) {

    ///**************************************************************************************************///
    /// Fait exactement comme la fonction display mais n'affiche pas les boutons                         ///
    ///**************************************************************************************************///

    m_backgroundSprite.setTexture(m_backgroundTexture);      // Load la texture du fond du jeu
    window->draw(m_backgroundSprite);                       // Dessine le fond du jeu

}