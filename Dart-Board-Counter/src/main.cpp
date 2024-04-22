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

unsigned long currentMillis = 0;

OneButton stickButton = OneButton(stickSwitchPin, true);

// initialize first game
Game *currentGame = new DartboardGame(301, lcd);
GameType currentGameType = DartBoardGame;

/// @brief returns state of joystick
/// @param pin
/// @return -2 hard down, -1 down, 0 no change, 1 up, 2 hard up)
int JoyStickHandler(int pin)
{
  int value = analogRead(pin);
  Serial.println(String(value));
  if (value >= 200 && value <= 800)
  {
    return 0;
  }
  else if (value >= 0 && value <= 199)
  {
    return -1;
  }
  else if (value >= 801)
  {
    return 1;
  }
}

void StickButtonClick(void *object)
{
  currentGame->HandleClick();
}


unsigned long lastStickMeasurement = 0;
unsigned long stickmeasurementInterval = 100;
void HandleStick(int xPin, int yPin)
{

  if(currentMillis <= (lastStickMeasurement + stickmeasurementInterval))
  {
    return;
  }

  lastStickMeasurement = currentMillis;


  int xValue = JoyStickHandler(xPin);
  int yValue = JoyStickHandler(yPin);

  // Serial.println(String(xValue) + "-" + String(yValue));

  // Serial.println(xValue);

  if (xValue == -1)
  {
    currentGame->HandleJoyStickDown();
  }
  if (xValue == 1)
  {
    currentGame->HandleJoyStickUp();
  }

  if (yValue == -1)
  {
    // currentGame->HandleJoyStickLeft();
  }
  if (yValue == 1)
  {
    // currentGame->HandleJoyStickRight();
  }
}

void setup()
{
  Serial.begin(9600);
  lcd->begin(16, 2);

  pinMode(A0, INPUT);

  pinMode(A1, INPUT);


  stickButton.attachClick(StickButtonClick, &stickButton);
}

void loop()
{
  currentMillis = millis();
  // Serial.println(String(JoyStickHandler(A1)));
  stickButton.tick();

  HandleStick(A0, A1);

  currentGame->Handler();

  // delay(10);
}
