#include "BoxingBagTimer.h"

BoxingBagTimer::BoxingBagTimer(LiquidCrystal *Lcd)
{
    this->lcd = Lcd;
    gameState = 0;
}

void BoxingBagTimer::Handler()
{
    currentMillis = millis();
    switch (gameState)
    {
    case 0: // Menu Screen
    {
        lcd->setCursor(0, 0);
        lcd->print("Boxing Timer       ");
        lcd->setCursor(0, 1);
        lcd->print("Click To Start       ");
        break;
    }
    case 1: // select number rounds
    {
        lcd->setCursor(0, 0);
        lcd->print("NumberOfRounds");
        // TODO
        lcd->setCursor(0, 1);
        lcd->print("Rounds: " + String(currentNumberSelection) + "          ");
        break;
    }
    case 2: // Select number of minutes per round
    {
        lcd->setCursor(0, 0);
        lcd->print("MinutesPerRound");
        // TODO
        lcd->setCursor(0, 1);
        lcd->print("Minutes: " + String(currentNumberSelection) + "            ");
        break;
    }
    case 3: // Select minutes between rounds
    {
        lcd->setCursor(0, 0);
        lcd->print("MinBetwenRounds");

        lcd->setCursor(0, 1);
        lcd->print("Minutes: " + String(currentNumberSelection) + "             ");
        break;
    }
    case 4: // Start Game Screen
    {
        lcd->setCursor(0, 0);
        lcd->print("Click to start          ");
        lcd->setCursor(0, 1);
        lcd->print("Round 1!! :)           ");
        break;
    }
    case 5: // Round Busy
    {
        if (currentMillis > (counterLastMillis + 1000))
        {
            countDownTimer.TickSecond(1);
            counterLastMillis = currentMillis;
        }

        int nrOfMinutesleft = (countDownTimer.GetTotalSeconds() / 60);
        int nrOfSecondsLeft = countDownTimer.GetTotalSeconds() - (nrOfMinutesleft * 60);

        if (nrOfSecondsLeft <= 0 && nrOfMinutesleft <= 0)
        {
            roundsCompleted++;
            Serial.println(roundsCompleted);
            if (roundsCompleted >= numberOfRoundsToDo)
            {
                gameState = 7;
                break;
            }
            this->gameState = 6;
            countDownTimer.AddMinutes(this->timeBetweenRounds);
            break;
        }

        lcd->setCursor(0, 0);
        lcd->print("CurrentRound-" + String(roundsCompleted + 1) + "         ");
        lcd->setCursor(0, 1);
        lcd->print("TimeLeft- " + String(nrOfMinutesleft) + ":" + String(nrOfSecondsLeft));
        break;
    }
    case 6: // Time between rounds busy
    {
        if (currentMillis > (counterLastMillis + 1000))
        {
            countDownTimer.TickSecond(1);
            counterLastMillis = currentMillis;
        }

        int nrOfMinutesleft = (countDownTimer.GetTotalSeconds() / 60);
        int nrOfSecondsLeft = countDownTimer.GetTotalSeconds() - (nrOfMinutesleft * 60);
        if (nrOfSecondsLeft <= 0 && nrOfMinutesleft <= 0)
        {
            tone(11, 262);
            delay(1000);
            noTone(11);
            this->gameState = 5;
            countDownTimer.AddMinutes(this->roundLengthMinutes);
            break;
        }

        lcd->setCursor(0, 0);
        lcd->print("Time Till Next:             ");
        lcd->setCursor(0, 1);
        lcd->print("Round: " + String(nrOfMinutesleft) + ":" + String(nrOfSecondsLeft) + "     ");
        break;
    }

    break;
    case 7: // End of all rounds
        lcd->setCursor(0, 0);
        lcd->print("Congrats,                ");
        lcd->setCursor(0, 1);
        lcd->print("Boxer :)                 ");
        break;
    default:
        break;
    }
}
void BoxingBagTimer::ResetGame()
{
}

void BoxingBagTimer::HandleClick()
{
    switch (gameState)
    {
    case 0: // Menu Screen
        gameState = 1;
        roundsCompleted = 0;
        break;
    case 1: // select number rounds
        numberOfRoundsToDo = currentNumberSelection;
        gameState = 2;
        lcd->clear();
        break;
    case 2: // Select number of minutes per round
        roundLengthMinutes = currentNumberSelection;
        gameState = 3;
        lcd->clear();

        break;
    case 3: // Select time between rounds
        timeBetweenRounds = currentNumberSelection;
        gameState = 4;
        lcd->clear();

        break;
    case 4: // Start Game

        countDownTimer.AddMinutes(this->roundLengthMinutes);
        tone(11, 262);
        delay(200);
        noTone(11);
        delay(200);
        tone(11, 262);
        delay(200);
        noTone(11);
        delay(200);
        tone(11, 262);
        delay(200);
        noTone(11);
        gameState = 5;
        lcd->clear();

        break;
    case 5: // Select time between rounds
        break;
    default:
        break;
    }
}
void BoxingBagTimer::HandleJoyStickUp()
{
    currentNumberSelection += 10;
}
void BoxingBagTimer::HandleJoyStickDown()
{
    currentNumberSelection -= 10;
}
void BoxingBagTimer::HandleJoyStickLeft()
{
    currentNumberSelection -= 1;
}
void BoxingBagTimer::HandleJoyStickRight()
{
    currentNumberSelection += 1;
}