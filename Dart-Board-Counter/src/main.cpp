// include the library code:
#include <LiquidCrystal.h>
#include <Arduino.h>
#include <Wire.h>
#include "DartboardGame.h"
#include "OneButton.h"
#include "GamesEnum.h"

// Lcd pions
const int rs = 9, en = 8, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal *lcd = new LiquidCrystal(rs, en, d4, d5, d6, d7);


// Stick pins
const int stickYPin = A0;
const int stickXpin = A1;
const int stickSwitchPin = 10;

OneButton stickButton =  OneButton(stickSwitchPin, true);

// initialize first game
Game *currentGame = new DartboardGame(301, lcd);
GameType currentGameType = DartBoardGame;



void StickButtonClick(void* object)
{
  currentGame->HandleClick();
}



void setup()
{
  Serial.begin(9600);
  lcd->begin(16, 2);

  stickButton.attachClick(StickButtonClick, &stickButton);
}


void loop()
{
  stickButton.tick();

  currentGame->Handler();


}
