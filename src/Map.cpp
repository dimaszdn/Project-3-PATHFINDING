#include<Map.h>

sf::Vector2i Map::getCellPos()
{
    sf::Vector2i cellPos = {-1, -1};
    sf::Vector2i mouse = sf::Mouse::getPosition(mWindow);
    if ((0 <= mouse.x && mouse.x < mapSizeX * cellSize) && (0 <= mouse.y && mouse.y < mapSizeY * cellSize))
    {
        cellPos.x = floor(mouse.x / cellSize);
        cellPos.y = floor(mouse.y / cellSize);
    }
    return cellPos;
}

void Map::inputUser()
{
    auto cellPos = this->getCellPos();
    if (cellPos.x != -1 && cellPos.y != -1)
    {
        if (1 == sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            map[cellPos.y][cellPos.x] = CELL::WALL;

        else if (1 == sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        {
            if (cellPos == finish)
                blockFinish = false;
            else if (cellPos == start)
                blockStart = false;

            map[cellPos.y][cellPos.x] = CELL::EMPTY;
        }

        else if (!blockStart && sf::Keyboard::isKeyPressed(sf::Keyboard::S) && cellPos != finish)
        {
            map[cellPos.y][cellPos.x] = CELL::START;
            start = {cellPos.x, cellPos.y};
            blockStart = true;
        }

        else if (!blockFinish && sf::Keyboard::isKeyPressed(sf::Keyboard::F) && cellPos != start)
        {
            map[cellPos.y][cellPos.x] = CELL::FINISH;
            finish = {cellPos.x, cellPos.y};
            blockFinish = true;
        }
    }
}

void Map::draw()
{
    sf::RectangleShape cell(sf::Vector2f(cellSize - 2.5, cellSize - 2.5));
    cell.setOutlineThickness(2.5);
    cell.setOutlineColor(sf::Color(128, 128, 128));

    for (int y = 0; y < mapSizeY; ++y)
    {
        for (int x = 0; x < mapSizeX; ++x)
        {
            cell.setPosition(x * cellSize, y * cellSize);
            switch (map[y][x])
            {
                case CELL::EMPTY:
                    cell.setFillColor(sf::Color(14, 41, 75));
                    break;
                case CELL::WALL:
                    cell.setFillColor(sf::Color::White);
                    break;
                case CELL::FINISH:
                    cell.setFillColor(sf::Color::Red);
                    break;
                case CELL::START:
                    cell.setFillColor(sf::Color::Green);
                    break;
                case CELL::VISUAL:
                    cell.setFillColor(sf::Color(66,170,255));
                    break;
                case CELL::PATH:
                    cell.setFillColor(sf::Color(252,232,131));
                    break;
            }
            mWindow.draw(cell);
        }
    }
}