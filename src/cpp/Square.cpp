#include "Square.hpp"

Square::Square()
{
    state = EMPTY;
    direction = RIGHT;
}

Square::Square(State state)
{
    this -> state = state;
    direction = RIGHT;
}