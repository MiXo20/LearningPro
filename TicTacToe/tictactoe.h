#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream>
namespace tictactoe
{

enum Pos {A,B,C,D,E,F,G,H,I};
enum Fig {figX='X',figO='O',empty};

void Hidecursor();
void PrintText(short x, short y, int text_col, int beckground_col, const char *text);
int GetKey(const Pos *field);
void GotoXY(short X, short Y);
void SetColor(int text, int background);

class Field
{
    short fx;
    short fy;
    Fig *fStatus;
    size_t moveCount=0;
    Pos cursor_pos=A;

public:
    Field(short x=0, short y=0);
    ~Field() { delete [] fStatus; }
    const Fig* GetStatus(){ return this->fStatus; }
    void PutFigure(Pos p,Fig f);
    bool Draw();
    bool Win(Fig f);

};

class Player
{
protected:
    Fig figure;
private:
    size_t move=0;

public:
    Player(Fig f=empty):figure(f){}
    Fig GetFigure();
    Pos Move(int key);
    virtual int MovePos(const Fig *field)=0;
};

class Cpu: public Player
{
public:
    Cpu(Fig f):Player(f){}
    int MovePos(const Fig *field);
};

class Human: public Player
{
public:
    Human(Fig f):Player(f){}
    int MovePos(const Fig *field);
};


}
#endif // TICTACTOE_H
