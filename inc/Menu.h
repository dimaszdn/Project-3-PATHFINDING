#pragma once

#include <SFML/Graphics.hpp>
#include <Info.h>

class Menu
{
private:
    sf::RenderWindow& mWindow;

    sf::Vector2i mMenuSize;

    int characterSizeTitle = 80;
    int characterSizeInfo = 60;

    Info title;
    Info bfsInfo;

public:
    Menu(sf::Vector2i menuSize, sf::RenderWindow& window) : mMenuSize(menuSize), mWindow(window)
    {}

    void setupTitle(const std::string& str);

    void setupBfsInfo(const std::string& str);

    void draw()
    {
        mWindow.draw(title.getText());
        mWindow.draw(bfsInfo.getText());
    }
};