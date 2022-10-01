#include "Game.hpp"
#include <iostream>

Game::Game()
{
    width = 10;
    height = 10;
    board = new Square[width * height];
}

Game::Game(int width, int height)
{
    this -> width = width;
    this -> height = height;
    board = new Square[width * height];
}

Game::~Game()
{
    delete board;

    for( Square* ptr : snake)
    {
        delete ptr;
    }
}

void Game::setSnake()
{
    int head_x = width / 2 - 1;
    int head_y = height / 2 - 1;
    int head_index = head_x + (width * head_y);
    board[ head_index ].state = SNAKE;

    snake.push_back( &board[ head_index] );

    for(int i = 1; i < snake_length; i++)
    {
        board[ head_index - i].state = SNAKE;
        snake.push_back(&board[ head_index - i]);
    }
}

void Game::draw()
{
    for( int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            std::cout << board[j + (width * i)].state;
        }
        std::cout<<std::endl;
    }
}