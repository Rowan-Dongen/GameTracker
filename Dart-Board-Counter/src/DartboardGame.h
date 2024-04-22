#ifndef DART_BOARD_GAME_H
#define DART_BOARD_GAME_H

#include "Game.h"
#include <OneButton.h>
#include "Pitches.h"

class DartboardGame : public Game
{
private:
    LiquidCrystal *lcd;
    bool lastTurn;
    bool lastWinner;

    int player1Score;
    int player2Score;
    int gameState;

    int currentScoreSelection;

    void handleShortPressStart(void *object);


    
    void PlayWinningTune();

public:
    DartboardGame(int startingCount, LiquidCrystal *Lcd);
    void Handler();

    void SetStartingCount(int count);
    void Player1Turn(int score);
    void Player2Turn(int score);
    void ResetGame();

    void HandleClick();
    void HandleJoyStickUp();
    void HandleJoyStickDown();
    void HandleJoyStickLeft();
    void HandleJoyStickRight();

    // ~DartboardGame();
};

#endif
