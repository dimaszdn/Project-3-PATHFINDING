#include <Menu.h>

#include <iostream>

void Menu::setupTitle(const std::string &str)
{
    try
    {
        title.setup(characterSizeTitle, sf::Color::Blue);
        title.setPos({(float)(mWindow.getSize().x - characterSizeTitle - (mMenuSize.x / 2)), 10});
        title.setString(str);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
}

void Menu::setupBfsInfo(const std::string &str)
{
    try
    {
        bfsInfo.setup(50, sf::Color::Blue);
        bfsInfo.setPos({(float)(mWindow.getSize().x - mMenuSize.x + 5), (float)(characterSizeInfo * 2)});
        bfsInfo.setString(str);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
}