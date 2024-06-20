#include <BFS.h>
#include <Cell.h>

void BFS::search()
{
    auto start = mMap.getStart();
    auto finish = mMap.getFinish();
    std::vector<sf::Vector2i> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    if (firstFuncCall)
    {
        dist[start.y][start.x] = 0;
        q.push(start);
        firstFuncCall = false;
        downTime = clock.getElapsedTime();
    }

    sf::Vector2i neighbour;

    if (!q.empty())
    {
        auto curCell = q.front();

        //если дошли до финиша, то всё успешно, считываем время и выходим из функции
        if (curCell.x == finish.x && curCell.y == finish.y)
        {
            status = STATUS::SUCCESS;
            allTime = clock.getElapsedTime();
            return;
        }

        //основная часть bfs
        q.pop();
        for (sf::Vector2i dir : dirs) //4 возможных соседа
        {
            neighbour = {curCell.x + dir.x, curCell.y + dir.y};
            if (this->insideInMap(neighbour))
            {
                CELL neighbourType = mMap.getCell(neighbour);
                if ((neighbourType == CELL::EMPTY || neighbourType == CELL::FINISH)
                    && dist[neighbour.y][neighbour.x] == -1)
                {
                    dist[neighbour.y][neighbour.x] = dist[curCell.y][curCell.x] + 1;
                    parents[neighbour.y][neighbour.x] = curCell;
                    q.push(neighbour);

                    //анимация
                    mMap.setCell(neighbour, CELL::VISUAL);
                }
            }
        }
    }
    else
    {
        allTime = clock.getElapsedTime();
        status = STATUS::FAIL;
    }
}

void BFS::showPath()
{
    auto start = mMap.getStart();
    auto finish = mMap.getFinish();
    for (sf::Vector2i cell = finish; cell != start; cell = parents[cell.y][cell.x])
        mMap.setCell(cell, CELL::PATH);
}