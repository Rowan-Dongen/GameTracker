#include "DartboardGame.h"

DartboardGame::DartboardGame(int startingCount, OneButton* stickButton)
{

    this->stickButton = stickButton;

    this->player1Score = startingCount;
    this->player2Score = startingCount;
}

void DartboardGame::Handler()
{


}

void DartboardGame::SetStartingCount(int count)
{
}
void DartboardGame::Player1Turn(int score)
{
}
void DartboardGame::Player2Turn(int score)
{

}
