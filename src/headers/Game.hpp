#include "Square.hpp"
#include <vector>
#include <string>

class Game{
public:
    int width;
    int height;
    const int snake_length = 3;
    Direction playerInput = RIGHT;
    bool playing;
    Square* board;
    std::vector<Square*> snake;
    //some strings for drawing the game
    std::string top_bottom_border; // = std::string(width + 2, '=');
    const char side_border = '|';

    Game();
    Game(int width, int height);
    ~Game();

    void setSnake();

    void setSquare();
    void draw();
    void getPlayerInput();
    void play();
    void move();
    void gameOver();
    void setBorders();
};