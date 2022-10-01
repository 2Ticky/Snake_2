#include "Square.hpp"
#include <vector>

class Game{
public:
    int width;
    int height;
    const int snake_length = 3;
    Square* board;

    Game();
    Game(int width, int height);
    ~Game();

    void setSnake();

    void setSquare();
    void draw();

};