#include "Square.hpp"
#include <vector>
#include <string>

class Game{
public:
    Game();
    Game(int width, int height);
    ~Game();
    void play();
    bool playing;

private:
    int width;
    int height;
    int snake_length = 3;
    Direction playerInput = RIGHT;
    
    Square* board;
    Square* food;
    std::vector<Square*> snake;
    //some strings for drawing the game
    std::string top_bottom_border; 
    const char side_border = '|';

    

    void setSnake();
    void setSquare();
    void draw();
    void getPlayerInput();
    void move();
    void checkSquare();
    void setBorders();
    void placeFood();
    void grow();
};