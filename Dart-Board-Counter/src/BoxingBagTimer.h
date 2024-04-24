#ifndef BOXINGBAGTIMER_H
#define BOXINGBAGTIMER_H
#include "Game.h"

class BoxingBagTimer : public Game
{
private:
    LiquidCrystal *lcd;

    unsigned int gameState;
    unsigned int currentNumberSelection;

    unsigned int numberOfRoundsToDo;
    unsigned int roundLengthMinutes;
    unsigned int timeBetweenRounds;

    unsigned int minutesLeftInRound;
    unsigned int secondsLeftInRound;
    unsigned int roundsCompleted;

public:
    BoxingBagTimer(LiquidCrystal *Lcd);
    void Handler();
    void ResetGame();

    void HandleClick();
    void HandleJoyStickUp();
    void HandleJoyStickDown();
    void HandleJoyStickLeft();
    void HandleJoyStickRight();

    // ~DartboardGame();
};

#endif
