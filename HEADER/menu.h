#ifndef CLUEDO_MENU_H
#define CLUEDO_MENU_H

#include "libraries.h"
#include "button.h"
#include "player.h"

class Menu {

private:

    std::vector<Button> m_buttons;

    sf::Texture m_backgroundTexture;

    sf::Sprite m_backgroundSprite;

    sf::Font m_titleFont;

    sf::Font m_textFont;

public:

    Menu();

    Menu(std::string backgroundPath);

    ~Menu() = default;

    void sendMousePos(sf::Vector2<int> mousePos);

    void sendClick(bool isPressed);

    int getButtonClicked();

    void setButtonText(int index, std::string text);

    std::string getButtonText(int index);

    void display(sf::RenderWindow *window);

    void displayRestricted(int fromThis, int toThis, sf::RenderWindow *window);

    void displayBackgroundOnly(sf::RenderWindow *window);

    void addButtons(int x, int y, int w, int h, sf::Color color, std::string text, bool clickable);

    void addButtons(int x, int y, int w, int h, sf::Color color, std::string text, bool clickable, std::string font, bool square);

    void displayTurnInfo(Player currentplayer, sf::RenderWindow *window);

    void initFont(std::string pathTitleFont, std::string pathMainFont);

    void changeButtonsColor (int indice, sf::Color newColor);

    void changeButtonsClickable (int indice, bool newBool);
};

#endif