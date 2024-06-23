#pragma once

#include <SFML/Graphics.hpp>
#include <WindowText.h>
#include <Button.h>

class Menu
{
private:
    sf::RenderWindow& mWindow;
    sf::Vector2i mMenuSize;

    int characterSizeTitle = 80;
    int characterSizeInfo = 60;
    WindowText title;
    WindowText bfsInfo;
    Button bfsButton;
    Button exitButton;

public:
    Menu(sf::Vector2i menuSize, sf::RenderWindow& window) : mMenuSize(menuSize), mWindow(window)
    {}

    void setTitle(const std::string& str);

    void setBfsInfo(const std::string& str, const sf::Color& color);

    void setButtonStartBfs();

    void setButtonExit();

    void inputUser(bool& startBfsButtonIsPressed, bool& exitButtonIsPressed)
    {
        if (bfsButton.isMouseOver(mWindow) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            startBfsButtonIsPressed = true;
        if (exitButton.isMouseOver(mWindow) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            exitButtonIsPressed = true;
    }

    void draw()
    {
        mWindow.draw(title.getText());
        mWindow.draw(bfsInfo.getText());
        bfsButton.draw(mWindow);
        exitButton.draw(mWindow);
    }
};