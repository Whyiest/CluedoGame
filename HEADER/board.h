#ifndef CLUEDO_BOARD_H
#define CLUEDO_BOARD_H

#include "libraries.h"
#include "cell.h"
#include "utilitaire.h"

class Board {

private:

    int m_cols;
    int m_rows;
    int m_cellWidth;
    int m_cellHeight;

    std::vector<std::vector<Cell *>> m_board;

    sf::Texture m_mapTexture;

    sf::Sprite m_mapSprite;

public:

    Board();

    ~Board() = default;

    void display(sf::RenderWindow *window);

    Cell* getCell(int x, int y);

    std::vector<Cell *> getOtherDoors(int type);

    int getCols();

    int getRows();

    int getCellWidht();

    int getCellHeight();

    string getRoomHere(int posX, int posY);
};

#endif
