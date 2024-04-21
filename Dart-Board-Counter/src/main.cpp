// include the library code:
#include <LiquidCrystal.h>
#include <Arduino.h>
#include <Wire.h>
#include "DartboardGame.h"
#include "OneButton.h"


//Lcd pions
const int rs = 9, en = 8, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Stick pins
const int stickYPin = A0;
const int stickXpin = A1;
const int stickSwitchPin = 10;

OneButton stickButton = OneButton(stickSwitchPin, true);
int gameState = 0;

DartboardGame dartGame = DartboardGame(301);


void LongPressStart(void *oneButton)
{
  gameState = 3;
}

// this function will be called when the button is released.
void LongPressStop(void *oneButton)
{
  Serial.print(((OneButton *)oneButton)->getPressedMs());
  Serial.println("\t - LongPressStop()\n");
}

// this function will be called when the button is held down.
void DuringLongPress(void *oneButton)
{
  Serial.print(((OneButton *)oneButton)->getPressedMs());
  Serial.println("\t - DuringLongPress()");
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

    // link functions to be called on events.
  stickButton.attachLongPressStart(LongPressStart, &stickButton);
  stickButton.attachDuringLongPress(DuringLongPress, &stickButton);
  stickButton.attachLongPressStop(LongPressStop, &stickButton);

  // stickButton.attachClick();

  stickButton.setLongPressIntervalMs(2000);

}

void loop() {
stickButton.tick();
  switch (gameState)
  {
  case 0: // Game yet to start
  lcd.setCursor (0, 0);
  lcd.print("click to start");
    break;
  case 1://Player 1 turn
    
    break;
  case 2://Player 2 turn
    break;
  case 3://Set starting count
    lcd.setCursor (0, 0);
  lcd.print("Select starting count");
    break;
  default:
    break;
  }

  // lcd.clear();
 
}



