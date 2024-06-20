#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <Map.h>
#include <BFS.h>

class App
{
private:
    sf::RenderWindow mWindow;
    sf::Color fontColor = {250,235,215};

    bool startBfsButtonIsPressed = false;

public:
    App() = default;

    ~App() = default;

    void setup(int windowW, int windowH, const std::string& caption)
    {
        mWindow.create(sf::VideoMode(windowW, windowH), caption);
        mWindow.setFramerateLimit(60);
    }

    void logic(BFS& bfs);

    void run();
};