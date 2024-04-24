#ifndef BOXINGBAGTIMER_H
#define BOXINGBAGTIMER_H
#include "Game.h"
#include "Counter.h"
#include <LiquidCrystal.h>

class BoxingBagTimer : public Game
{
private:
    LiquidCrystal *lcd;
    Counter countDownTimer = Counter(0, 0, 0);
    unsigned long currentMillis = 0;
    unsigned long counterLastMillis = 0;
    unsigned long counterLastMillis2 = 0;

    unsigned int gameState = 0;
    unsigned int currentNumberSelection = 0;

    unsigned int numberOfRoundsToDo = 0;
    unsigned int roundLengthMinutes = 0;
    unsigned int timeBetweenRounds = 0;

    unsigned int minutesLeftInRound = 0;
    unsigned int secondsLeftInRound = 0;

    unsigned int minutesTillNextRound = 0;
    unsigned int secondsTillNextRound = 0;

    unsigned int roundsCompleted = 0;

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
