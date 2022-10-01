#include "Game.hpp"
#include <iostream>
int main()
{
    Game game;
    game.setSnake();
    game.draw();

    for(Square* snakePart : game.snake)
    {
        std::cout << snakePart -> state << std::endl;
    }
    return 0;
}