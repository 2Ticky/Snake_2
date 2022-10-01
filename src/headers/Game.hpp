#include "Square.hpp"
#include <vector>

class Game{
public:
    int width;
    int height;
    const int snake_length = 3;
    Square* board;
    std::vector<Square*> snake;
    Game();
    Game(int width, int height);
    ~Game();

    void setSnake();

    void setSquare();
    void draw();

};