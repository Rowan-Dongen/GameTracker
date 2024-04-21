#include "DartboardGame.h"
#include <Arduino.h>
DartboardGame::DartboardGame(int startingCount, LiquidCrystal *Lcd)
{
    this->currentScoreSelection = 100;
    this->lcd = Lcd;
    gameState = 0;
    this->player1Score = startingCount;
    this->player2Score = startingCount;
    this->lastTurn = false;
}

void DartboardGame::Handler()
{

    switch (gameState)
    {
    case 0: // Before Game
        lcd->setCursor(0, 0);
        lcd->print("Click to start");
        break;
    case 1: // Started Game - Selecting starting score
        lcd->setCursor(0, 0);
        lcd->print("Click to start");
        break;
    case 2: // Selecting score
        /* code */
        if (Player1Turn)
            break;

    default:
        break;
    }
}

void DartboardGame::SetStartingCount(int count)
{
    return;
}

void DartboardGame::Player1Turn(int score)
{
    player1Score -= score;
    // TODO handle busts and maybe calc possible wins
}

void DartboardGame::Player2Turn(int score)
{
    // TODO handle busts and maybe calc possible wins
    player1Score -= score;
}

void DartboardGame::HandleClick()
{
    switch (gameState)
    {
    case 0: // Before Game
        gameState = 1;
        break;
    case 1: // Started Game - Selecting starting score

        break;
    case 2: // Selecting score
    // TODO check which whose turn it is, select score
    default:
        break;
    }
}

void DartboardGame::HandleJoyStickUp() 
{
    currentScoreSelection += 10;
}
void DartboardGame::HandleJoyStickDown() 
{
    currentScoreSelection -= 10;
}
void DartboardGame::HandleJoyStickLeft()
{
    currentScoreSelection -= 1;
}
void DartboardGame::HandleJoyStickRight()
{
    currentScoreSelection -= 1;
}
