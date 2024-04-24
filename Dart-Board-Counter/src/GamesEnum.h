#ifndef GAMES_ENUM_H
#define GAMES_ENUM_H
#include <Arduino.h>

#define NROFGAMES 2
enum GameType {DartBoardGame, BoxingGame};

String gameNames[2] = {"DartGame", "Boxing Game"};

#endif