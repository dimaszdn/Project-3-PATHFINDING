#include <App.h>
#include <Status.h>
#include <FloatToString.h>

void App::logic(BFS& bfs, Menu& menu)
{
    if (startBfsButtonIsPressed)
    {
        STATUS status = bfs.getStatus();

        switch (status)
        {
            case STATUS::SUCCESS:
                startBfsButtonIsPressed = false;
                bfs.showPath();
                menu.setupBfsInfo("Path length: " + std::to_string(bfs.getShortDist()) +
                                      "\nTime spent: " + floatToString(bfs.getWorkTime(), 3));
                break;

            case STATUS::FAIL:
                startBfsButtonIsPressed = false;
                break;

            case STATUS::PROCESS:
                bfs.search();
                break;
        }
    }
}

void App::run()
{

    Map map(mWindow, mMenuW);
    BFS bfs(map);

    Menu menu({mMenuW, mMenuH}, mWindow);
    menu.setupTitle("INFO");

    while (mWindow.isOpen())
    {
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mWindow.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                mWindow.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
                startBfsButtonIsPressed = true;

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                startBfsButtonIsPressed = false;
        }

        this->logic(bfs, menu);

        mWindow.clear(fontColor);

        map.inputUser();

        menu.draw();
        map.draw();

        mWindow.display();
    }
}