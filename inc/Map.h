#pragma once

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <Cell.h>

class Map
{
private:
    std::vector<std::vector<CELL>> map{};

    sf::RenderWindow& mWindow;

    bool blockStart{};
    bool blockFinish{};

    int cellSize{};
    size_t mapSizeY{};
    size_t mapSizeX{};

    sf::Vector2i start{};
    sf::Vector2i finish{};

public:
    explicit Map(sf::RenderWindow& window, int menuW) : mWindow(window)
    {
        cellSize = 40;
        blockStart = false;
        blockFinish = false;
        start = {-1, -1};
        finish = {-1, -1};
        mapSizeX = (mWindow.getSize().x - menuW) / cellSize;
        mapSizeY = mWindow.getSize().y / cellSize;
        map.resize(mapSizeY, std::vector<CELL>(mapSizeX, CELL::EMPTY));
    }

    [[nodiscard]] size_t getMapSizeY() const
    {
        return mapSizeY;
    }

    [[nodiscard]] size_t getMapSizeX() const
    {
        return mapSizeX;
    }

    [[nodiscard]] sf::Vector2i getStart() const
    {
        return start;
    }

    [[nodiscard]] sf::Vector2i getFinish() const
    {
        return finish;
    }

    [[nodiscard]] CELL getCell(const sf::Vector2i& cellPos) const
    {
        return map[cellPos.y][cellPos.x];
    }

    void setCell(const sf::Vector2i& pos, CELL typeCell)
    {
        if (pos != start && pos != finish)
            map[pos.y][pos.x] = typeCell;
    }

    void inputUser();

    sf::Vector2i getCellPos();

    void draw();
};