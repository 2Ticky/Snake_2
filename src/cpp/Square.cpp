#include "Square.hpp"

Square::Square()
{
    state = EMPTY;
    direction = RIGHT;
}

Square::Square(State state, Direction direction)
{
    this -> state = state;
    this -> direction = direction;
}