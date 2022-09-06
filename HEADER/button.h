#ifndef CLUEDO_BUTTON_H
#define CLUEDO_BUTTON_H

#include "libraries.h"

class Button {

private:

    int m_x;
    int m_y;
    int m_w;
    int m_h;

    sf::Color m_color;

    sf::RectangleShape m_rect;

    sf::Font m_font;

    sf::Text m_text;

    bool m_clickable;

    bool m_mouseOn = false;

    bool m_isPressed = false;

    bool m_clicked = false;

public:

    Button(int x = 0, int y = 0, int w = 0, int h = 0, sf::Color color = sf::Color::Black, std::string text = "", bool clickable = false);

    ~Button() = default;

    void setFont(std::string font);

    void enableSquare(bool square);

    void sendMousePos(sf::Vector2<int> mousePos);

    void sendClick(bool isPressed);

    bool isClicked();

    void setText(std::string text);

    std::string getText();

    void display(sf::RenderWindow *window);

    void changeColor(sf::Color newColor);

    void changeClickable(bool newbool);
};

#endif