#include <App.h>
#include <Status.h>

void App::logic(BFS &bfs)
{
    if (startBfsButtonIsPressed)
    {
        STATUS status = bfs.getStatus();

        switch (status)
        {
            case STATUS::SUCCESS:
                startBfsButtonIsPressed = false;
                bfs.showPath();
                std::cout << "Short dist: " << bfs.getShortDist() << "\n";
                std::cout << "Time work: " << bfs.getWorkTime() << "\n";
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
    Map map(mWindow);
    BFS bfs(map);

    while (mWindow.isOpen())
    {
        sf::Event event{};

        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mWindow.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                mWindow.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
                startBfsButtonIsPressed = true;

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                startBfsButtonIsPressed = false;
            }
        }

        this->logic(bfs);

        mWindow.clear(fontColor);

        map.draw();
        map.inputUser();

        mWindow.display();
    }
}