#ifndef GAMES_ENUM_H
#define GAMES_ENUM_H
#include <Arduino.h>

#define NROFGAMES 4
enum GameType {DartBoardGame, BoxingGame, Soon, Soon2};

String gameNames[NROFGAMES] = {"DartGame", "Boxing Game", "Coming Soon!", "Coming Soon 2!"};

#endif