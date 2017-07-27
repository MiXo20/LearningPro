#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include "tictactoe.h"

using namespace tictactoe;

HANDLE hConsole;    //HANDLE hStdout
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

Fig Player::GetFigure()
{
    return figure;
}

Pos Player::Move(int key)
{
    for(;;)
    {
        switch(key)
        {
        case 0:
        {
            move++;
            return A;
        }
        case 1:
        {
            move++;
            return B;
        }
        case 2:
        {
            move++;
            return C;
        }
        case 3:
        {
            move++;
            return D;
        }
        case 4:
        {
            move++;
            return E;
        }
        case 5:
        {
            move++;
            return F;
        }
        case 6:
        {
            move++;
            return G;
        }
        case 7:
        {
            move++;
            return H;
        }
        case 8:
        {
            move++;
            return I;
        }
        }
    }
}

bool Field::Win(Fig f)
{
    for(size_t i=0;i<9;i=i+3)
        if(fStatus[i]==f&&fStatus[i+1]==f&&fStatus[i+2]==f)
            return true;
    for(size_t i=0;i<3;i++)
        if(fStatus[i]==f&&fStatus[i+3]==f&&fStatus[i+6]==f)
            return true;
    if((fStatus[0]==f&&fStatus[4]==f&&fStatus[8]==f)||(fStatus[2]==f&&fStatus[4]==f&&fStatus[6]==f)) return true;
    return false;
}

Field::Field(short x, short y)
{
    fx=x; fy=y;
    fStatus= new Fig [9];
    for(size_t i=0;i<9;i++)
        fStatus[i]=empty;
    short d=4;
    while(d<10)
    {
        for(short i=0;i<14;i++)
        {
            GotoXY(i+fx,d+fy);
            SetColor(12,0);
            std::cout << '-';
            GotoXY(d+fx,i+fy);
            std::cout << '|';
        }
        d+=5;
    }
}

void Field::PutFigure(Pos p,Fig f)
{
    short X=fx,Y=fy;
    switch(p)
    {
    case A:
    {
        X=X+0;Y=Y+0;
        fStatus[0]=f;
        moveCount++;
        break;
    }
    case B:
    {
        X=X+5;Y=Y+0;
        fStatus[1]=f;
        moveCount++;
        break;
    }
    case C:
    {
        X=X+10;Y=Y+0;
        fStatus[2]=f;
        moveCount++;
        break;
    }
    case D:
    {
        X=X+0;Y=Y+5;
        fStatus[3]=f;
        moveCount++;
        break;
    }
    case E:
    {
        X=X+5;Y=Y+5;
        fStatus[4]=f;
        moveCount++;
        break;
    }
    case F:
    {
        X=X+10;Y=Y+5;
        fStatus[5]=f;
        moveCount++;
        break;
    }
    case G:
    {
        X=X+0;Y=Y+10;
        fStatus[6]=f;
        moveCount++;
        break;
    }
    case H:
    {
        X=X+5;Y=Y+10;
        fStatus[7]=f;
        moveCount++;
        break;
    }
    case I:
    {
        X=X+10;Y=Y+10;
        fStatus[8]=f;
        moveCount++;
        break;
    }

    }
    switch(f)
    {
    case figX:
    {
        for(short i=0;i<4;i++)
        {
            SetColor(5,0);
            GotoXY(X+i,Y+i);
            std::cout <<'*';
            GotoXY(X+3-i,Y+i);
            std::cout <<'*';;
            Sleep(50);
        }
        break;
    }
    case figO:
    {
        for(short i=1;i<3;i++)
        {
            SetColor(7,0);
            GotoXY(X+i,Y);
            std::cout <<'*';
            GotoXY(X,Y+i);
            std::cout <<'*';
            GotoXY(X+i,Y+3);
            std::cout <<'*';
            GotoXY(X+3,Y+i);
            std::cout <<'*';
            Sleep(50);
        }
        break;
    }
    }
}

bool Field::Draw()
{
    if (moveCount==9)
        return true;
    return false;
}

int Cpu::MovePos(const Fig *field)
{
    srand(time(0));
    for(;;)
    {
    int key=rand()%9;
        switch(key)
        {
        case 0:
        {
            if(field[0]!=empty) break;
            return 0;
        }
        case 1:
        {
            if(field[1]!=empty) break;
            return 1;
        }
        case 2:
        {
            if(field[2]!=empty) break;
            return 2;
        }
        case 3:
        {
            if(field[3]!=empty) break;
            return 3;
        }
        case 4:
        {
            if(field[4]!=empty) break;
            return 4;
        }
        case 5:
        {
            if(field[5]!=empty) break;
            return 5;
        }
        case 6:
        {
            if(field[6]!=empty) break;
            return 6;
        }
        case 7:
        {
            if(field[7]!=empty) break;
            return 7;
        }
        case 8:
        {
            if(field[8]!=empty) break;
            return 8;
        }
        default: break;
        }
    }
}

int Human::MovePos(const Fig *field)
{
    for(;;)
    {
        int c=0;
        c=getch();
        switch(c)
        {
        case 113:
        {
            if(field[0]!=empty) break;
            return 0;
        }
        case 119:
        {
              if(field[1]!=empty) break;
              return 1;
        }
        case 101:
        {
            if(field[2]!=empty) break;
            return 2;
        }
        case 97:
        {
            if(field[3]!=empty) break;
            return 3;
        }
        case 115:
        {
            if(field[4]!=empty) break;
            return 4;
        }
        case 100:
        {
            if(field[5]!=empty) break;
            return 5;
        }
        case 122:
        {
            if(field[6]!=empty) break;
            return 6;
        }
        case 120:
        {
            if(field[7]!=empty) break;
            return 7;
        }
        case 99:
        {
            if(field[8]!=empty) break;
            return 8;
        }
        default: break;
        }
    }
}

void tictactoe::PrintText(short x, short y, int text_col, int beckground_col,const char* text)
{
    GotoXY(x,y);
    SetColor(text_col,beckground_col);
    std::cout << text;
}

void tictactoe::GotoXY(short X, short Y)
{
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

void tictactoe::SetColor(int text, int background)
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void tictactoe::Hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
