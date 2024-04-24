// include the library code:
#include <LiquidCrystal.h>
#include <Arduino.h>
#include <Wire.h>
#include "DartboardGame.h"
#include "OneButton.h"
#include "GamesEnum.h"
#include <fcntl.h>

byte newChar1[8] = {
    B00100,
    B01110,
    B10101,
    B00100,
    B00100,
    B00100,
    B00100,
    B00100};

byte newChar2[8] = {
    B00100,
    B00100,
    B00100,
    B00100,
    B00100,
    B10101,
    B01110,
    B00100};

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
Game *currentGame;
GameType currentGameType = DartBoardGame;

// device settings
int deviceState = 0;
int gameSelection = 0;

/// @brief returns state of joystick
/// @param pin
/// @return -2 hard down, -1 down, 0 no change, 1 up, 2 hard up)
int JoyStickHandler(int pin)
{
  int value = analogRead(pin);

  // int calculatedValue = map(value, 50, 1000, -2, 2);
  if (value >= 300 && value <= 700)
  {
    return 0;
  }
  else if (value >= 0 && value <= 299)
  {
    return -1;
  }
  else if (value >= 701)
  {
    return 1;
  }
  // return calculatedValue;
}

void StickButtonClick(void *object)
{
  switch (deviceState)
  {
  case 0: // Selcting game
    switch (gameSelection)
    {
    case 0: //"Selected game 0"
      currentGame = new DartboardGame(301, lcd);
      break;
    case 1: //"Selected game 1"
      currentGame = new BoxingTimer();
      break;
    default:
      break;
    }
    deviceState = 1;
    break;
  case 1: // Playing game
    currentGame->HandleClick();
    break;
  default:
    break;
  }
}

void StickButtonLongPressStart(void *object)
{
  // delete currentGame;
  deviceState = 0;
}

unsigned long lastStickMeasurement = 0;
unsigned long stickmeasurementInterval = 250;
void HandleStick(int xPin, int yPin)
{
  Serial.println("cide is run");
  if (currentMillis < (lastStickMeasurement + stickmeasurementInterval))
  {
    return;
  }
  lastStickMeasurement = currentMillis;
  int xValue = JoyStickHandler(xPin);
  int yValue = JoyStickHandler(yPin);

  switch (deviceState)
  {
  case 0: // Selecting game
    if (xValue == -1)
    {
      gameSelection--;
    }
    if (xValue == 1)
    {
      gameSelection++;
    }
    if (gameSelection < 0)
    {
      gameSelection = NROFGAMES;
    }
    if (gameSelection >= NROFGAMES)
    {
      gameSelection = 0;
    }
    break;
  case 1: // In game
    if (xValue == -1)
    {
      currentGame->HandleJoyStickDown();
      return;
    }
    if (xValue == 1)
    {
      currentGame->HandleJoyStickUp();
      return;
    }
    if (yValue == -1)
    {
      currentGame->HandleJoyStickLeft();
      return;
    }
    if (yValue == 1)
    {
      currentGame->HandleJoyStickRight();
      return;
    }
    break;
  default://DEFAULT
    break;
  }
}

void setup()
{
  Serial.begin(9600);
  lcd->begin(16, 2);
  lcd->createChar(0, newChar1);
  lcd->createChar(1, newChar2);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  stickButton.attachClick(StickButtonClick, &stickButton);
  stickButton.attachDuringLongPress(StickButtonLongPressStart, &stickButton);
}

void loop()
{
  // Hardware Handlers
  currentMillis = millis();
  HandleStick(A0, A1);
  stickButton.tick();

  // Device handler
  switch (deviceState)
  {
  case 0: // Selecting game
    lcd->setCursor(0, 0);
    lcd->print("Select Game");
    lcd->write((byte)0);
    lcd->write((byte)1);

    lcd->setCursor(0, 1);
    {
      lcd->print(gameNames[gameSelection] + "               ");
    }
    break;
  case 1: // Ingame
    currentGame->Handler(); 
    HandleStick(A0, A1);
    break;
  default:
    break;
  }
}
