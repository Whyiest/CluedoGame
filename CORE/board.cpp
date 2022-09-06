#include "../HEADER/board.h"


using namespace std;

Board::Board() {

    ///******************************************************************************************************//
    /// Pour définir les cases du plateau. Chaque nombre représente un type de case. Du point de vue client, //
    /// le tableau ci-dessous ne sera pas visible mais sera trés utile en revanche pour le debug ou un       //
    /// futur changement de map du côté développeur.                                                         //
    ///******************************************************************************************************//

    std::vector<std::vector<int>> cellType = {
            {-1, -1, -1,  -1, -1,  -1,  -1,  -1,  -1, -1, -1, -1,  -1,  -1,  -1, -1,  -1,  -1,  -1,  -1,  -1,  -1, -1,  -1,  -1,  -1,  -1, -1},
            {-1, -1, -1,  -1, -1,  -1,  -1,  -1,  -1, -1, -1, -1,  -1,  -1,  -1, 7,   7,   7,   7,   7,   7,   -1, -1,  -1,  -1,  -1,  -1, -1},
            {-1, -1, -1,  2,  2,   2,   2,   -1,  -1, 0,  -1, -1,  0,   -1,  -1, 7,   7,   7,   7,   7,   7,   -1, -1,  11,  11,  11,  11, -1},
            {-1, -1, -1,  2,  2,   2,   200, 0,   0,  0,  0,  0,   0,   0,   0,  700, 7,   7,   7,   7,   700, 0,  0,   110, 11,  11,  11, -1},
            {-1, -1, -1,  2,  2,   2,   200, 0,   0,  0,  0,  0,   0,   0,   0,  700, 7,   7,   7,   7,   700, 0,  0,   110, 11,  11,  11, -1},
            {-1, -1, -1,  2,  200, 200, 2,   -1,  -1, -1, -1, 0,   0,   -1,  -1, 7,   7,   7,   7,   7,   7,   -1, -1,  11,  110, 110, 11, -1},
            {-1, -1, -1,  -1, 0,   0,   -1,  -1,  -1, -1, 5,  500, 500, 5,   -1, 7,   7,   7,   7,   7,   7,   -1, -1,  -1,  0,   0,   -1, -1},
            {-1, 1,  1,   -1, 0,   0,   -1,  3,   3,  -1, 5,  5,   5,   5,   -1, 7,   7,   700, 700, 7,   7,   -1, -1,  -1,  0,   0,   -1, -1},
            {-1, 1,  100, 0,  0,   0,   0,   300, 3,  -1, 5,  5,   500, 5,   -1, -1,  -1,  0,   0,   -1,  -1,  -1, -1,  -1,  0,   0,   0,  -1},
            {-1, 1,  100, 0,  0,   0,   0,   300, 3,  -1, -1, -1,  0,   -1,  -1, -1,  -1,  0,   0,   0,   800, 8,  8,   -1,  0,   0,   -1, -1},
            {-1, 1,  1,   -1, 0,   0,   -1,  3,   3,  -1, -1, -1,  0,   -1,  -1, -1,  -1,  0,   0,   0,   800, 8,  8,   -1,  0,   0,   -1, -1},
            {-1, -1, -1,  -1, 0,   0,   -1,  -1,  -1, -1, -1, 6,   600, 6,   6,  -1,  -1,  0,   0,   -1,  8,   8,  8,   -1,  0,   0,   0,  -1},
            {-1, -1, -1,  4,  400, 400, 4,   -1,  -1, -1, -1, 6,   6,   6,   6,  -1,  -1,  0,   0,   -1,  -1,  -1, -1,  -1,  0,   0,   -1, -1},
            {-1, -1, -1,  4,  4,   4,   400, 0,   0,  0,  -1, 6,   6,   6,   6,  -1,  9,   900, 900, 9,   -1,  -1, -1,  -1,  0,   0,   -1, -1},
            {-1, -1, -1,  4,  4,   4,   400, 0,   0,  0,  -1, 6,   600, 600, 6,  -1,  9,   9,   9,   9,   -1,  -1, 12,  12,  120, 120, 12, -1},
            {-1, -1, -1,  4,  4,   4,   4,   -1,  0,  0,  -1, -1,  0,   0,   -1, -1,  9,   9,   9,   900, 0,   0,  120, 12,  12,  12,  12, -1},
            {-1, -1, -1,  -1, -1,  -1,  -1,  -1,  0,  0,  0,  0,   0,   0,   0,  0,   900, 9,   9,   900, 0,   0,  120, 12,  12,  12,  12, -1},
            {-1, -1, -1,  -1, -1,  -1,  -1,  -1,  0,  0,  0,  0,   0,   0,   0,  0,   900, 9,   9,   9,   -1,  -1, 12,  12,  12,  12,  12, -1},
            {-1, -1, -1,  -1, -1,  -1,  -1,  -1,  0,  -1, -1, -1,  -1,  0,   -1, -1,  9,   9,   9,   9,   -1,  -1, -1,  -1,  -1,  -1,  -1, -1},
            {-1, -1, -1,  -1, -1,  -1,  -1,  -1,  -1, -1, -1, -1,  -1,  -1,  -1, -1,  -1,  -1,  -1,  -1,  -1,  -1, -1,  -1,  -1,  -1,  -1, -1},
    };

    ///------------------------- Définition de la taille des cellules --------------------------//

    m_cols = cellType[0].size();
    m_rows = cellType.size();
    m_cellWidth = 2 * (width - margin) / 3 / m_cols;
    m_cellHeight = (height - margin) / m_rows;

    ///-------------------------------- Création des cellules --------------------------------//

    for (int i = 0; i < m_cols; ++i) {
        std::vector<Cell *> temporary(m_rows);
        for (int j = 0; j < m_rows; ++j) {
            temporary[j] = new Cell(i * m_cellWidth + margin / 2, j * m_cellHeight + margin / 2, m_cellWidth,
                                    m_cellHeight, cellType[j][i]);
        }
        m_board.push_back(temporary);
    }

    ///------------------------- Définition pour chaque cellule des accès --------------------------//


    for (int i = 0; i < m_cols; ++i) {

        for (int j = 0; j < m_rows; ++j) {

            std::vector<bool> temporary = {true, true, true, true};

            if (!m_board[i][j]->getIsDoor()) {

                if (j != 0 && !m_board[i][j - 1]->getIsDoor())
                    if (m_board[i][j]->getType() != m_board[i][j - 1]->getType()) temporary[0] = false;

                if (i < m_cols - 1 && !m_board[i + 1][j]->getIsDoor())
                    if (m_board[i][j]->getType() != m_board[i + 1][j]->getType()) temporary[1] = false;

                if (j < m_rows - 1 && !m_board[i][j + 1]->getIsDoor())
                    if (m_board[i][j]->getType() != m_board[i][j + 1]->getType()) temporary[2] = false;

                if (i != 0 && !m_board[i - 1][j]->getIsDoor())
                    if (m_board[i][j]->getType() != m_board[i - 1][j]->getType()) temporary[3] = false;

                m_board[i][j]->setWalls(temporary);
            }
        }
    }

    ///------------------------- Définition des pièces correspondantes --------------------------//


    for (int i = 0; i < m_cols; ++i) {

        for (int j = 0; j < m_rows; ++j) {

            m_board[i][j]->setRoomName("couloir");

            if (m_board[i][j]->getType() == 1 || m_board[i][j]->getType() == 100) {
                m_board[i][j]->setRoomName("reactor");
            }
            if (m_board[i][j]->getType() == 2 || m_board[i][j]->getType() == 200) {
                m_board[i][j]->setRoomName("upperEngine");
            }
            if (m_board[i][j]->getType() == 3 || m_board[i][j]->getType() == 300) {
                m_board[i][j]->setRoomName("security");
            }
            if (m_board[i][j]->getType() == 4 || m_board[i][j]->getType() == 400) {
                m_board[i][j]->setRoomName("lowerEngine");
            }
            if (m_board[i][j]->getType() == 5 || m_board[i][j]->getType() == 500) {
                m_board[i][j]->setRoomName("medbay");
            }
            if (m_board[i][j]->getType() == 6 || m_board[i][j]->getType() == 600) {
                m_board[i][j]->setRoomName("electrical");
            }
            if (m_board[i][j]->getType() == 7 || m_board[i][j]->getType() == 700) {
                m_board[i][j]->setRoomName("cafeteria");
            }
            if (m_board[i][j]->getType() == 8 || m_board[i][j]->getType() == 800) {
                m_board[i][j]->setRoomName("admin");
            }
            if (m_board[i][j]->getType() == 9 || m_board[i][j]->getType() == 900) {
                m_board[i][j]->setRoomName("storage");
            }
            if (m_board[i][j]->getType() == 11 || m_board[i][j]->getType() == 110) {
                m_board[i][j]->setRoomName("weapons");
            }
            if (m_board[i][j]->getType() == 12 || m_board[i][j]->getType() == 120) {
                m_board[i][j]->setRoomName("shields");
            }
        }
    }
    m_mapTexture.loadFromImage(util::newImage("../DATA/Others/gameMap.jpg", width, height));
    m_mapTexture.setSmooth(true);
}

///************************************************* FIN CONSTRUCTEUR ******************************************************//


void Board::display(sf::RenderWindow *window) {

    ///**************************************************************************************************///
    /// Permet l'affichage du plateau image et du plateau debug                                          ///
    ///**************************************************************************************************///

    m_mapSprite.setTexture(m_mapTexture);
    window->draw(m_mapSprite);

    if (ENABLEDEBUG == 1) {
        for (int i = 0; i < m_cols; ++i) {
            for (int j = 0; j < m_rows; ++j) {
                m_board[i][j]->display(window);
            }
        }
    }

}


vector<std::vector<Cell *>> getBoard() {

    ///**************************************************************************************************///
    /// Getter permettant de récupérer toutes les cases du plateau.                                      ///
    ///**************************************************************************************************///

    return getBoard();
}

Cell *Board::getCell(int x, int y) {

    ///**************************************************************************************************///
    /// Getter permettant de récupérer une case à une coordonée précise du plateau                       ///
    ///**************************************************************************************************///

    if (x < m_cols && x > 0 && y < m_rows && y > 0) return m_board[x][y];
    else exit(1);
}

int Board::getCols() {
    return m_cols;
}

int Board::getRows() {
    return m_rows;
}

std::vector<Cell *> Board::getOtherDoors(int type) {

    ///**************************************************************************************************///
    /// Permet de récupérer les portes d'une pièce                                                       ///
    ///**************************************************************************************************///

    std::vector<Cell *> otherDoors;

    for (int i = 0; i < m_cols; ++i) {
        for (int j = 0; j < m_rows; ++j) {
            if (m_board[i][j]->getType() == type && m_board[i][j]->getIsDoor()) otherDoors.push_back(m_board[i][j]);
        }
    }

    return otherDoors;
}

int Board::getCellWidht() {

    ///**************************************************************************************************///
    /// Getter permettant de récupérer  la largeur de cellules du plateau.                               ///
    ///**************************************************************************************************///

    return m_cellWidth;
}

int Board::getCellHeight() {

    ///**************************************************************************************************///
    /// Getter permettant de récupérer  la hauteur de cellules du plateau.                               ///
    ///**************************************************************************************************///

    return m_cellHeight;
}

string Board::getRoomHere(int posX, int posY) {
    string temps;
    temps = m_board[posX][posY]->getRoomName();
    return temps;
}

