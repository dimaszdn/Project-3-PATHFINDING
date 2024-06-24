#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <Map.h>
#include <BFS.h>
#include <Menu.h>

class App
{
private:
    sf::RenderWindow mWindow;
    sf::Event event{};
    sf::Color fontColor = {250,235,215};

    int mMenuW{};
    int mMenuH{};
    bool startBfsButtonIsPressed = false;
    bool exitButtonIsPressed = false;
    bool manualButtonIsPressed = false;

public:
    App() = default;

    ~App() = default;

    void setup(int windowW, int windowH, const std::string& caption)
    {
        mWindow.create(sf::VideoMode(windowW, windowH), caption, sf::Style::Titlebar);
        mWindow.setFramerateLimit(60);
    }

    void setMenuSize(int menuW, int menuH)
    {
        mMenuW = menuW;
        mMenuH = menuH;
    }

    void logic(BFS& bfs, Menu& menu);

    void run();
};