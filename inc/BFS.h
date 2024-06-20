#pragma once

#include <queue>

#include <Map.h>
#include <Status.h>

class BFS
{
private:
    Map& mMap;

    //для поиска в ширину
    std::queue<sf::Vector2i> q;
    std::vector<std::vector<int>> dist;
    std::vector<std::vector<sf::Vector2i>> parents;

    //некоторые остановочные параметры
    bool firstFuncCall = true;
    STATUS status;

    //для замера времени работы
    sf::Clock clock;
    sf::Time downTime;
    sf::Time allTime;

public:
    BFS(Map& map) : mMap(map), status(STATUS::PROCESS)
    {
        dist.resize(map.getMapSize(), std::vector<int>(map.getMapSize(), -1));
        parents.resize(map.getMapSize(), std::vector<sf::Vector2i>(map.getMapSize()));
    }

    bool insideInMap(const sf::Vector2i& pos)
    {
        if ((0 <= pos.x && pos.x < mMap.getMapSize()) && (0 <= pos.y && pos.y < mMap.getMapSize()))
            return true;
        return false;
    }

    STATUS getStatus()
    {
        return status;
    }

    [[nodiscard]] int getShortDist() const
    {
        return dist[mMap.getFinish().y][mMap.getFinish().x];
    }

    float getWorkTime()
    {
        return allTime.asSeconds() - downTime.asSeconds();
    }

    void search();

    void showPath();
};