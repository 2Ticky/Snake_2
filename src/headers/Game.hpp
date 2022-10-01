#include "Square.hpp"
#include <vector>

class Game{
public:

    int width;
    int height;
    Square* board;

    Game();
    Game(int width, int height);
private:
    void setSnake();

};