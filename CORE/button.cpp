#include "../HEADER/button.h"

///*************************************************************************************************************************///

Button::Button(int x, int y, int w, int h, sf::Color color, std::string text, bool clickable) {

    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
    m_clickable = clickable;
    m_color = color;

    m_rect.setPosition(m_x, m_y);
    m_rect.setSize(sf::Vector2f(w, h));
    m_rect.setFillColor(color);
    m_rect.setOutlineThickness(5);

    if (!m_font.loadFromFile("../DATA/Fonts/In your face, joffrey!.ttf")) std::cerr;
    m_text.setString(text);
    m_text.setCharacterSize(m_h);
    m_text.setPosition(m_x + m_w / 2 - (m_text.getCharacterSize() / 3.5 * text.size()) / 2,
                       m_y + m_h / 2 - m_text.getCharacterSize() / 1.5);
    m_text.setStyle(sf::Text::Regular);
    m_text.setFillColor(sf::Color::Black);
    m_text.setOutlineThickness(h / 50);
}

///*************************************************************************************************************************///



void Button::setFont(std::string font) {

    ///**************************************************************************************************//
    /// La fonction ci-desous permet d'attribuer au texte contenu dans un bouton, une police spécifique  //
    ///**************************************************************************************************//

    if (!m_font.loadFromFile(font)) std::cerr;
}

void Button::enableSquare(bool square) {

    ///**************************************************************************************************//
    /// La fonction ci-desous permet dans un bouton d'activer ou non un contour                          //
    ///**************************************************************************************************//

    if (square) m_rect.setOutlineThickness(5);
    else m_rect.setOutlineThickness(0);
}

void Button::sendMousePos(sf::Vector2<int> mousePos) {

    ///**************************************************************************************************//
    /// La fonction ci-desous permet de communiquer la position de la souris au programme                //
    ///**************************************************************************************************//

    if (mousePos.x < m_x + m_w && mousePos.x > m_x && mousePos.y < m_y + m_h && mousePos.y > m_y) m_mouseOn = true;
    else m_mouseOn = false;
}

void Button::sendClick(bool isPressed) {

    ///**************************************************************************************************//
    /// La fonction ci-desous permet de de détécter si un bouton est préssé, et de signaler son clic     //
    ///**************************************************************************************************//

    if (m_clickable) {
        if (m_mouseOn && !isPressed && m_isPressed) {
            m_isPressed = false;
            m_clicked = true;
        }
        if (m_mouseOn && isPressed) m_isPressed = true;
    }
}

bool Button::isClicked() {

    ///**************************************************************************************************//
    /// La fonction ci-desous permet mettre à jour l'état de la classe après un clic                     //
    ///**************************************************************************************************//

    if (m_clicked) {
        m_clicked = false;
        return true;
    } else return false;
}

void Button::setText(std::string text) {

    ///**************************************************************************************************//
    /// Permet de modifier le texte d'un bouton                                                          //
    ///**************************************************************************************************//

    m_text.setString(text);
    m_text.setPosition(m_x + m_w / 2 - (m_text.getCharacterSize() / 3.5 * text.size()) / 2,
                       m_y + m_h / 2 - m_text.getCharacterSize() / 1.5);
}

std::string Button::getText() {

    ///**************************************************************************************************//
    /// Permet de récupérer le texte d'un bouton                                                         //
    ///**************************************************************************************************//

    return m_text.getString();
}

void Button::display(sf::RenderWindow *window) {

    ///**************************************************************************************************//
    /// La fonction ci-desous permet dd'afficher un bouton en fonction de ses caractéristiques           //
    ///**************************************************************************************************//

    if (m_mouseOn && m_clickable) {
        m_rect.setOutlineColor(sf::Color::Green);
        m_text.setOutlineColor(sf::Color::Green);
    } else {
        m_rect.setOutlineColor(sf::Color::White);
        m_text.setOutlineColor(sf::Color::White);
    }
    window->draw(m_rect);
    m_text.setFont(m_font);
    window->draw(m_text);
}

void Button::changeColor(sf::Color newcolor) {

    ///**************************************************************************************************///
    /// Permet de changer la couleur du fond d'un bouton                                                 ///
    ///**************************************************************************************************///

    m_rect.setFillColor(newcolor);
}

void Button::changeClickable(bool newbool){

    ///**************************************************************************************************///
    /// Permet de changer si le bouton doit être ou non cliquable                                        ///
    ///**************************************************************************************************///

    m_clickable = newbool;
}
