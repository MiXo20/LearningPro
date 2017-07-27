#ifndef GAME_H
#define GAME_H
#include "tictactoe.h"

using namespace tictactoe;

class Game
{
    Fig P0figure,P1figure;
    bool gametype;
    short curPosition=3;
    bool again;
    void PrintCursor(short x,short y);
    void DeleteCursor(short x,short y);
    void PlayAgain();

public:

    bool Menu();
    void PickFigure();
    void GameGo();

};
#endif // GAME_H
