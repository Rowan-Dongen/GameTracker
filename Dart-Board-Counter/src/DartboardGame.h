#ifndef DART_BOARD_GAME_H
#define DART_BOARD_GAME_H

#include "Game.h"
#include <OneButton.h>
#include "Pitches.h"
#include "LiquidCrystal.h"

class DartboardGame : public Game
{
private:
    LiquidCrystal *lcd;
    bool lastTurn;
    bool lastWinner;
    int gameState;

    unsigned int currentScoreSelection;
    unsigned int startingScore;
    unsigned int player1Score;
    unsigned int player2Score;

    
    unsigned int player1Wins;
    unsigned int player2Wins;

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
