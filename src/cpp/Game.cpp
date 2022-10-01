#include "Game.hpp"
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>


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

void Game::play()
{
    playing = true;
    setSnake();

    while(playing)
    {
        draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        getPlayerInput(); 
        move();
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


void Game::getPlayerInput()
{
    
    if( (GetKeyState(VK_UP) & 0x8000) && snake[0] -> direction != DOWN)
    {
        playerInput = UP;
    }
    else if( (GetKeyState(VK_LEFT) & 0x8000) && snake[0] -> direction != RIGHT)
    {
        playerInput = LEFT;
    }
    else if( (GetKeyState(VK_DOWN) & 0x8000) && snake[0] -> direction != UP)
    {
        playerInput = DOWN;
    }
    else if( (GetKeyState(VK_RIGHT) & 0x8000) && snake[0] -> direction != LEFT)
    {
        playerInput = RIGHT;
    }
}

void Game::move()
{
    Direction old, thisDirect;
    thisDirect = playerInput;
    snake[snake_length - 1] -> state = EMPTY;

    for(int i = 0; i < snake_length; i++)
    {
        old = snake[i] -> direction;
        snake[i] -> direction = thisDirect;
        
        switch(thisDirect)
        {
            case UP:
                snake[i] -= width;
                break;
            case DOWN:
                snake[i] += width;
                break;
            case RIGHT:
                snake[i]++;
                break;
            case LEFT:
                snake[i]--;
                break;
        }

        snake[i] -> state = SNAKE;
        snake[i] -> direction = thisDirect;
        thisDirect = old;
    }
}

