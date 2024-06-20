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
    size_t mapSize{};

    sf::Vector2i start{};
    sf::Vector2i finish{};

public:
    explicit Map(sf::RenderWindow& window) : mWindow(window)
    {
        cellSize = 40;
        blockStart = false;
        blockFinish = false;
        start = {-1, -1};
        finish = {-1, -1};
        mapSize = mWindow.getSize().y / cellSize;
        map.resize(mapSize, std::vector<CELL>(mapSize, CELL::EMPTY));
    }

    [[nodiscard]] size_t getMapSize() const
    {
        return mapSize;
    }

    [[nodiscard]] sf::Vector2i getStart() const
    {
        return start;
    }

    [[nodiscard]] sf::Vector2i getFinish() const
    {
        return finish;
    }

    [[nodiscard]] CELL getCell(sf::Vector2i cellPos) const
    {
        return map[cellPos.y][cellPos.x];
    }

    void setCell(sf::Vector2i pos, CELL typeCell)
    {
        if (pos != start && pos != finish)
            map[pos.y][pos.x] = typeCell;
    }

    void inputUser();

    sf::Vector2i getCellPos();

    void draw();
};