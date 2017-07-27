#include "tictactoe.h"
#include <conio.h>
#include "windows.h"
#include <iostream>
#include "game.h"

using namespace tictactoe;

int main()
{
    Game g;
    while(g.Menu())
    {
        g.PickFigure();
        g.GameGo();
    }
    return 0;
}


