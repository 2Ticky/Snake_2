#include "Game.hpp"

Game::Game()
{
    width = 20;
    height = 20;
    board = new Square[width * height];
}

Game::Game(int width, int height)
{
    this -> width = width;
    this -> height = height;
    board = new Square[width * height];
}