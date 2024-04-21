#ifndef DART_BOARD_GAME_H
#define DART_BOARD_GAME_H

#include "Game.h"
#include <OneButton.h>

class DartboardGame : public Game
{
private:

    bool lastTurn;
    int player1Score;
    int player2Score;

    OneButton *stickButton;

public:
    DartboardGame(int startingCount, OneButton* stickButton);
    void Handler();

    void SetStartingCount(int count);
    void Player1Turn(int score);
    void Player2Turn(int score);
    // ~DartboardGame();
};


#endif

