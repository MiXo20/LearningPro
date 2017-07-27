#include "game.h"
#include "tictactoe.h"
#include <windows.h>
#include <MMSystem.h>
#include <ctime>

using namespace tictactoe;

void Game::PrintCursor(short x,short y)
{
    PrintText(x,y,4,0,"**");
}

void Game::DeleteCursor(short x,short y)
{
    PrintText(x,y,0,0,"**");
}

void Game::PlayAgain()
{
    PrintText(10,21,12,0,"Play again?  Y/N");
    for(;;)
    {
        if(GetKeyState(78)<0)
        {
            again=false;
            break;
        }
        if(GetKeyState(89)<0) break;
    }
}

bool Game::Menu()
{
    Hidecursor();
    system("cls");
    PrintText(10,1,8,0,"Tic Tac Toe Game");
    PrintText(10,3,14,0,"Human VS Human");
    PrintText(10,5,12,0,"Human VS Cpu");
    PrintText(10,7,3,0,"Exit");
    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
    PrintCursor(7,curPosition);
    for(;;)
    {
        if(GetKeyState(VK_DOWN)<0)
        {
            PlaySound(L"cursor.wav", NULL, SND_FILENAME | SND_ASYNC);
            Sleep(150);
            DeleteCursor(7,curPosition);
            if(curPosition==7) curPosition-=6;
            PrintCursor(7,curPosition+=2);
        }
        if(GetKeyState(VK_UP)<0)
        {
            PlaySound(L"cursor.wav", NULL, SND_FILENAME | SND_ASYNC);
            Sleep(150);
            DeleteCursor(7,curPosition);
            if(curPosition==3) curPosition+=6;
            PrintCursor(7,curPosition-=2);
        }
        if(GetKeyState(VK_RETURN)<0)
        {
            PlaySound(L"cursor.wav", NULL, SND_FILENAME | SND_ASYNC);
            Sleep(150);
            if(curPosition==3)
            {
                gametype=0;
                return true;
            }
            if(curPosition==5)
            {
                gametype=1;
                return true;
            }
            return false;
        }
    }

}

void Game::PickFigure()
{
    system("cls");
    short y=3;
    PrintText(10,1,8,0,"Tic Tac Toe Game");
    PrintText(10,3,7,0,"Pick Your figure:     X");
    PrintText(10,5,9,0,"                      O");
    PrintCursor(28,y);
    for(;;)
    {
        if(GetKeyState(VK_DOWN)<0)
        {
            PlaySound(L"cursor.wav", NULL, SND_FILENAME | SND_ASYNC);
            Sleep(150);
            DeleteCursor(28,y);
            if(y==5) y-=4;
            PrintCursor(28,y+=2);
        }
        if(GetKeyState(VK_UP)<0)
        {
            PlaySound(L"cursor.wav", NULL, SND_FILENAME | SND_ASYNC);
            Sleep(150);
            DeleteCursor(28,y);
            if(y==3) y+=4;
            PrintCursor(28,y-=2);
        }
        if(GetKeyState(VK_RETURN)<0)
        {
            PlaySound(L"cursor.wav", NULL, SND_FILENAME | SND_ASYNC);
            Sleep(150);
            if(y==3)
            {
                P0figure=figX;P1figure=figO;
                return;
            }
            if(y==5)
            {
                P1figure=figX;P0figure=figO;
                return;
            }
        }
    }
}

void Game::GameGo()
{
    Player *p[2];
    if(gametype==0)
    {
        p[0]=new Human(P0figure);
        p[1]=new Human(P1figure);
    }
    else
    {
        p[0]=new Human(P0figure);
        p[1]=new Cpu(P1figure);
    }
    srand(time(0));
    again=true;
    while(again)
    {
        PlaySound(L"game.wav", NULL, SND_FILENAME | SND_ASYNC);
        system("cls");
        Field field(10,5);
        for(size_t i=0;;i++)
        {
            GotoXY(10,4);
            SetColor(10,0);
            std::cout << "Player "<<static_cast<char>(p[i%2]->GetFigure())<<" turn:";
            field.PutFigure(p[i%2]->Move(p[i%2]->MovePos(field.GetStatus())),p[i%2]->GetFigure());
            if(field.Win(p[i%2]->GetFigure()))
            {
                GotoXY(10,20);
                SetColor(12,0);
                std::cout << "Player "<<static_cast<char>(p[i%2]->GetFigure())<<" wins!!!";
                PlayAgain();
                SetColor(0,0);
                break;
            }
            if(field.Draw())
            {
                PrintText(10,20,12,0,"Draw!");
                PlayAgain();
                SetColor(0,0);
                break;
            }
            GotoXY(10,4);
            SetColor(0,0);
            std::cout << "Player "<<static_cast<char>(p[i%2]->GetFigure())<<" turn:";
        }
    }
}
