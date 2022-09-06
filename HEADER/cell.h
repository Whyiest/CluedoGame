#ifndef CLUEDO_CELL_H
#define CLUEDO_CELL_H

#include "libraries.h"

using namespace std;


class Cell {

private:

    string m_roomName;

    int m_x = 0;
    int m_y = 0;
    int m_w = 0;
    int m_h = 0;
    int m_cellType = 0;

    bool m_isDoor = false;

    vector<bool> m_isOpen = {true, true, true, true}; ///haut droite bas gauche

public:

    Cell(int x, int y, int w, int h, int cellType);

    ~Cell() = default;

    void display(sf::RenderWindow *window);

    void setWalls(std::vector<bool> isOpen);

    bool getIsDoor() const;

    int getType() const;

    int getX();

    int getY();

    bool isTopOpen();

    bool isBottomOpen();

    bool isRightOpen();

    bool isLeftOpen();

    void setRoomName(string newName);

    string getRoomName();
};

#endif
