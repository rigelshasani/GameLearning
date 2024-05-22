#include "Game.h"
int main()
{
    Game game;

    // Init srand
    std::srand(static_cast<unsigned>(time(NULL)));
    // Game loop
    while (game.running())
    {
        // Update
        game.update();
        // Render
        game.render();
    }

    return 0;
}
