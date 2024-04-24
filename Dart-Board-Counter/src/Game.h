#ifndef GAME_H
#define GAME_H
#include <Arduino.h>
#include <LiquidCrystal.h>

class Game
{
private:
public:
    Game(/* args */)
    {
    }
    virtual void Handler() = 0;
    virtual void HandleClick() = 0;
    virtual void HandleJoyStickUp() = 0;
    virtual void HandleJoyStickDown() = 0;
    virtual void HandleJoyStickLeft() = 0;
    virtual void HandleJoyStickRight()= 0;
    virtual void ResetGame() = 0;
};

#endif