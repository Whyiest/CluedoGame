#include "../HEADER/cell.h"

///*************************************************************************************************************************//

Cell::Cell(int x, int y, int w, int h, int cellType) {
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
    if (cellType < 100) m_cellType = cellType;
    else {
        float temp = (float)cellType / 100;
        if ((temp - int(temp)) != 0) temp *= 10;
        m_cellType = temp;
        m_isDoor = true;
    }
}

///*************************************************************************************************************************//



void Cell::setWalls(std::vector<bool> isOpen) {

    ///**************************************************************************************************///
    /// Cette fonction permet de rédimensionner l'épaisseur d'un mur pour le transformer en porte        ///
    ///**************************************************************************************************///

    m_isOpen.resize(4);
    m_isOpen = isOpen;
}



void Cell::display(sf::RenderWindow *window) {

    ///**************************************************************************************************//
    /// Cette fonction permet l'affichage d'une cellule selon les côtés qui sont ouverts et sa couleur   //
    ///**************************************************************************************************//

    sf::RectangleShape rect;
    rect.setPosition(m_x, m_y);
    rect.setSize(sf::Vector2f(m_w, m_h));

    switch (m_cellType) {

        /// --> Gestion couleur

        case 0:
            rect.setFillColor(sf::Color(230, 230, 210, 100));
            break;
      /*  case 1:
            rect.setFillColor(sf::Color(225, 0, 0, 255));
            break;
        case 2:
            rect.setFillColor(sf::Color::Green);
            break;
        case 3:
            rect.setFillColor(sf::Color::Blue);
            break;
        case 4:
            rect.setFillColor(sf::Color::Yellow);
            break;
        case 5:
            rect.setFillColor(sf::Color::Magenta);
            break;
        case 6:
            rect.setFillColor(sf::Color::Cyan);
            break;
        case 7:
            rect.setFillColor(sf::Color(150, 150, 150));
            break;
        case 8:
            rect.setFillColor(sf::Color(0, 150, 150));
            break;
        case 9:
            rect.setFillColor(sf::Color(150, 150, 0));
            break;
        case 10:
            rect.setFillColor(sf::Color(150, 0, 150));
            break;
        case 11:
            rect.setFillColor(sf::Color(100, 0, 100));
            break;
        case 12:
            rect.setFillColor(sf::Color(150, 100, 0));
            break;*/
        default:
            rect.setFillColor(sf::Color(0,0,0,100));
            break;
    }

    rect.setOutlineColor(sf::Color(120, 35, 30, 255));
    rect.setOutlineThickness(1);
    window->draw(rect);

    /// --> Gestion des portes et murs

    if (!m_isOpen[0]) {
        sf::RectangleShape upLine;
        upLine.setPosition(m_x, m_y);
        upLine.setSize(sf::Vector2f(m_w, 4));
        upLine.setFillColor(sf::Color(120, 35, 30, 255));
        window->draw(upLine);
    }

    if (!m_isOpen[1]) {
        sf::RectangleShape rightLine;
        rightLine.setPosition(m_x + m_w - 4, m_y);
        rightLine.setSize(sf::Vector2f(4, m_h));
        rightLine.setFillColor(sf::Color(120, 35, 30, 255));
        window->draw(rightLine);
    }

    if (!m_isOpen[2]) {
        sf::RectangleShape downLine;
        downLine.setPosition(m_x, m_y + m_h - 4);
        downLine.setSize(sf::Vector2f(m_w, 4));
        downLine.setFillColor(sf::Color(120, 35, 30, 255));
        window->draw(downLine);
    }

    if (!m_isOpen[3]) {
        sf::RectangleShape leftLine;
        leftLine.setPosition(m_x, m_y);
        leftLine.setSize(sf::Vector2f(4, m_h));
        leftLine.setFillColor(sf::Color(120, 35, 30, 255));
        window->draw(leftLine);
    }
}




///--------------------------- Vérifications des ouvertures autour de la cellule -----------------------///

bool Cell::getIsDoor() const {
    return m_isDoor;
};

int Cell::getType() const {
    return m_cellType;
}

bool Cell::isTopOpen() {
    return m_isOpen[0];
}

bool Cell::isBottomOpen() {
    return m_isOpen[2];
}

bool Cell::isRightOpen() {
    return m_isOpen[1];
}

bool Cell::isLeftOpen() {
    return m_isOpen[3];
}

int Cell::getX() {
    return m_x;
}

int Cell::getY() {
    return m_y;
}

void Cell::setRoomName(string newName) {
    m_roomName = newName;
}

string Cell::getRoomName() {
    return m_roomName;
}