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
                menu.setBfsInfo("Path length: " + std::to_string(bfs.getShortDist()) +
                                      "\nTime spent: " + floatToString(bfs.getWorkTime(), 3),
                                      sf::Color::Blue);
                break;

            case STATUS::FAIL:
                startBfsButtonIsPressed = false;
                menu.setBfsInfo("The path could\nnot be found!", sf::Color::Red);
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
    menu.setTitle("<INFO>");
    menu.setBfsInfo("Path length: \nTime spent: ", sf::Color::Blue);
    menu.setButtonStartBfs();
    menu.setButtonExit();
    menu.setButtonManual();

    while (mWindow.isOpen())
    {
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mWindow.close();

            if (exitButtonIsPressed)
                mWindow.close();
        }

        this->logic(bfs, menu);

        mWindow.clear(fontColor);

        map.inputUser();
        menu.inputUser(startBfsButtonIsPressed, exitButtonIsPressed, manualButtonIsPressed);

        menu.draw();
        map.draw();

        mWindow.display();
    }
}