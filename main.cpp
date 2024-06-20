#include<App.h>

int main()
{
    App app;
    app.setup(1680, 1000, "PATHFINDING");
    app.setMenuSize(400, 1000);
    app.run();
    return 0;
}
