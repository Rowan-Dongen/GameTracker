#include "DartboardGame.h"
#include <Arduino.h>
#include "pitches.h"
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
    player2Score -= score;
}

void DartboardGame::HandleClick()
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
        // TODO check which whose turn it is, select score
        if (lastTurn == false)
        {
            Player1Turn(currentScoreSelection);
        }
        else
        {
            Player2Turn(currentScoreSelection);
        }
        lastTurn = !lastTurn;
        gameState = 2;

        if (player1Score == 0)
        {
            PlayWinningTune();
            gameState = 3;
        }
        if (player2Score == 0)
        {
            PlayWinningTune();
            gameState = 3;
        }
    case 3:
        lcd->setCursor(0, 0);
        lcd->print("Player " + String((!lastTurn) + 1) + " Wins!!     ");
        lcd->setCursor(0, 1);
        lcd->print("                                ");
        break;
    default:
        break;
    }
}

void DartboardGame::ResetGame()
{
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

    // iterate over the notes of the melody:

    for (int thisNote = 0; thisNote < 8; thisNote++)
    {

        // to calculate the note duration, take one second divided by the note type.

        // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

        int noteDuration = 1000 / noteDurations[thisNote];

        tone(11, melody[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.

        // the note's duration + 30% seems to work well:

        int pauseBetweenNotes = noteDuration * 1.30;

        delay(pauseBetweenNotes);

        // stop the tone playing:

        noTone(11);
    }
}