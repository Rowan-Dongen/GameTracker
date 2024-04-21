#ifndef GAME_H
#define GAME_H
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
};



#endif