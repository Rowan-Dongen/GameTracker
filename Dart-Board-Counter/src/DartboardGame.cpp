#include "DartboardGame.h"
#include <Arduino.h>
#include "pitches.h"
DartboardGame::DartboardGame(int startingCount, LiquidCrystal *Lcd)
{
    player1Wins = 0;
    player2Wins = 0;
    int startingScore = startingCount;
    this->currentScoreSelection = 100;
    this->lcd = Lcd;
    gameState = 0;
    this->player1Score = startingCount;
    this->player2Score = startingCount;
    this->lastTurn = false;
}

void DartboardGame::Handler() // Code to be run, per gamestate, loop.
{

    switch (gameState)
    {
    case 0: // Before Game
        lcd->setCursor(0, 0);
        lcd->print("Click to start");
        break;
    case 1: // Started Game - Selecting starting score
        lcd->setCursor(0, 0);
        lcd->print("Select Starting Score");

        lcd->setCursor(0, 1);
        lcd->print(String(currentScoreSelection) + "       ");

        break;
    case 2: // Selecting score

        // lcd->clear();
        lcd->setCursor(0, 0);
        lcd->print("P1=" + String(player1Score) + " P2=" + String(player2Score) + "                ");
        lcd->setCursor(0, 1);
        lcd->print("P" + String(lastTurn + 1) + " Score" + String(currentScoreSelection) + "           ");
        break;
    case 3:
        lcd->setCursor(0, 0);
        lcd->print("Player " + String((!lastTurn) + 1) + " Wins!!      ");
        lcd->setCursor(0, 1);
        lcd->print("Wins= p1-" + String(player1Wins) + " p2-" + String(player2Wins));
        break;
    default:
        break;
    }
}

void DartboardGame::HandleClick() // Code to be run, per gamestate on joystick click event
{
    switch (gameState)
    {
    case 0: // Before Game
        gameState = 1;
        break;
    case 1: // Started Game - Selecting starting score
        player1Score = currentScoreSelection;
        player2Score = currentScoreSelection;
        gameState = 2;
        break;
    case 2: // Selecting score
        if (lastTurn == false)
        {
            Player1Turn(currentScoreSelection);
        }
        else
        {
            Player2Turn(currentScoreSelection);
        }
        lastTurn = !lastTurn;
        break;
    case 3:
        this->ResetGame();
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
    int currentScore = player1Score;

    if ((currentScore - score) > 0)
    {
        player1Score -= score;
    }

    else if ((player1Score - score) == 0)
    {
        PlayWinningTune();
        player1Wins++;
        player1Score = startingScore;
        gameState = 3;
    }
}

void DartboardGame::Player2Turn(int score)
{
    int currentScore = player2Score;

    if ((currentScore - score) > 0)
    {
        player2Score -= score;
    }

    else if ((player2Score - score) == 0)
    {
        PlayWinningTune();
        player2Wins++;
        player2Score = startingScore;
        gameState = 3;
    }
}

void DartboardGame::ResetGame()
{
    gameState = 0;
    player1Score = 0;
    player2Score = 0;
    lcd->clear();
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
    currentScoreSelection += 1;
}

int melody[] = {

    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

    4, 8, 8, 4, 4, 4, 4, 4};

void DartboardGame::PlayWinningTune()
{

    for (int thisNote = 0; thisNote < 8; thisNote++)
    {
        int noteDuration = 1000 / noteDurations[thisNote];

        tone(11, melody[thisNote], noteDuration);

        int pauseBetweenNotes = noteDuration * 1.30;

        delay(pauseBetweenNotes);

        noTone(11);
    }
}