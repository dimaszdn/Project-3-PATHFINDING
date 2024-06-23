#include <Menu.h>
#include <iostream>

void Menu::setTitle(const std::string &str)
{
    try
    {
        title.setString(str);
        title.setup(80, sf::Color::Blue);

        float x = mWindow.getSize().x - mMenuSize.x;
        float y = 30;
        title.setPosition({x, y});
        title.centerByWidth(mMenuSize.x);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
}

void Menu::setBfsInfo(const std::string &str, const sf::Color& color)
{
    try
    {
        bfsInfo.setString(str);
        bfsInfo.setup(50, color);

        float x = mWindow.getSize().x - mMenuSize.x + 10;
        float y = bfsInfo.getText().getCharacterSize() * 3;
        bfsInfo.setPosition({x, y});
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
}

void Menu::setButtonStartBfs()
{
    try
    {
        bfsButton.setup({300, 100}, sf::Color::White);
        bfsButton.setText("Start BFS", 100 / 2, sf::Color::Blue);

        float x = mWindow.getSize().x - mMenuSize.x;
        float y = 540;
        bfsButton.setPosition({x, y});
        bfsButton.centerByWidth(mMenuSize.x);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
}

void Menu::setButtonExit()
{
    try
    {
        exitButton.setup({300, 100}, sf::Color::White);
        exitButton.setText("Exit", 100 / 2, sf::Color::Blue);

        float x = mWindow.getSize().x - mMenuSize.x;
        float y = 840;
        exitButton.setPosition({x, y});
        exitButton.centerByWidth(mMenuSize.x);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
}

