#include "BoxingBagTimer.h"

BoxingBagTimer::BoxingBagTimer(LiquidCrystal *lcd)
{
    this->lcd = lcd;
    gameState = 0;
}
void BoxingBagTimer::Handler()
{
    switch (gameState)
    {
    case 0: // Menu Screen
        lcd->setCursor(0, 0);
        lcd->print("Boxing Timer    ");
        lcd->setCursor(0, 1);
        lcd->print("Click To Start  ");
        break;
    case 1: // select number rounds
        lcd->setCursor(0, 0);
        lcd->print("NumberOfRounds");
        // TODO
        break;
    case 2: // Select number of minutes per round
        lcd->setCursor(0, 0);
        lcd->print("MinutesPerRound");
        // TODO
        break;
    case 3: // Select minutes between rounds
        lcd->setCursor(0, 0);
        lcd->print("Round" + String(roundsCompleted + 1));

        lcd->setCursor(0, 1);
        // TODO print minutes/seconds left
        break;
    case 4: // Select minutes between rounds
        break;
    case 5: // Round Busy
        break;
    case 6://Time between rounds
        break;
    case 7://End of all rounds
        break;
    default:
        break;
    }
}
void BoxingBagTimer::ResetGame()
{
}

void BoxingBagTimer::HandleClick()
{
    switch (gameState)
    {
    case 0: // Menu Screen
        gameState = 1;
        break;
    case 1: // select number rounds
        numberOfRoundsToDo = currentNumberSelection;
        gameState = 2;
        break;
    case 2: // Select number of minutes per round
        roundLengthMinutes = currentNumberSelection;
        gameState = 3;
        break;
    case 3: // Select time between rounds
        timeBetweenRounds = currentNumberSelection;
        gameState = 4;
        break;
    case 4: // Select time between rounds
        break;
    case 5: // Select time between rounds
        break;
    default:
        break;
    }
}
void BoxingBagTimer::HandleJoyStickUp()
{
    currentNumberSelection += 10;
}
void BoxingBagTimer::HandleJoyStickDown()
{
    currentNumberSelection -= 10;
}
void BoxingBagTimer::HandleJoyStickLeft()
{
    currentNumberSelection -= 1;
}
void BoxingBagTimer::HandleJoyStickRight()
{
    currentNumberSelection += 1;
}