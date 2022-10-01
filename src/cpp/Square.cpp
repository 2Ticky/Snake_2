#include "Square.hpp"

Square::Square()
{
    state = FOOD;
    direction = RIGHT;
}

Square::Square(State state)
{
    this -> state = state;
    direction = RIGHT;
}