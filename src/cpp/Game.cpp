#include "Game.hpp"
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>


Game::Game()
{
    width = 12;
    height = 12;
    board = new Square[this -> width  * this -> height]; //add borders
    setBorders();
}

Game::Game(int width, int height)
{
    //+2 for borders
    this -> width = width + 2;
    this -> height = height + 2;
    board = new Square[this -> width  * this -> height];
    setBorders();

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
        gameOver();
        
        if(playing)
        {
            move();
        }
        
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

void Game::gameOver()
{
    switch(playerInput)
    {
        case UP:
            playing = (snake[0] - width) -> state != FLOOR_CEILING;
        case DOWN:
            playing = (snake[0] + width) -> state != FLOOR_CEILING;
        case RIGHT:
            playing = (snake[0] + 1) -> state != WALL;
        case LEFT:
            playing = (snake[0] - 1) -> state != WALL;
    }
}

void Game::setBorders()
{
    for(int i = 0; i < width; i++)
    {
        board[i].state = FLOOR_CEILING;
    }

    for(int i = 1; i < height - 1; i++)
    {
        board[width * i].state = WALL;
        board[width * i + width - 1] = WALL;
    }

    for(int i = 0; i < width; i++)
    {
        board[i + width * (height - 1)].state = FLOOR_CEILING;
    }

}

