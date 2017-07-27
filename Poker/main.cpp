#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>


using namespace std;

int Menu();
int Enter(int &num);

class Player
{
 public:
    int sum[20];
    int total=0;

    void Throw(int dice_num,int roll_num);
};

int main()
{
    int roll_num;
    bool exit=true;
    Player P1,P2;

    srand(time(0));
    while(exit)
    {

        int draws=0;
        switch(Menu())
        {
            case 1:
            {
                int dice_num;
                P1.total=0; P2.total=0;
                system ("cls");
                cout <<"Enter number of dices :\n";
                Enter(dice_num);
                cout <<"Enter number of rolls: \n";
                Enter(roll_num);
                for(int i=0; i<roll_num; i++)
                {
                    system("cls");
                    cout<<"Tour "<< i+1 << endl;
                    cout <<"Player 1 turn: \n";
                    cin.get();
                    P1.Throw(dice_num, i);
                    cout <<"Player 2 turn: \n";
                    cin.get();
                    P2.Throw(dice_num, i);
                    if(P1.sum[i]==P2.sum[i])
                    { cout << "Draw!\n\n"; draws++; }
                    else if(P1.sum[i]<P2.sum[i])
                    { cout <<"Player 2 wins!\n\n"; P2.total++; }
                    else
                    { cout <<"Player 1 wins!\n\n"; P1.total++; }
                    cin.get();
                }
            }
            case 2:
            {
                system ("cls");
                cout <<"-------TOTAL------\n\a";
                cout <<"Player1 : "<<P1.total<<" victoris.\n";
                cout <<"Player2 : "<<P2.total<<" victoris.\n";
                cout <<"Draws: "<<draws<<endl;
                cin.get();
                cin.get();
                break;
            }
            case 3:
            {
                exit=false;
                break;
            }
        }
    }
    return 0;
}

int Menu()
{
    int choise=0;
    system("cls");
    cout <<"---Welcome to Dice Poker!!!---\n";
    cout <<"        1.Play\n";
    cout <<"        2.Stats\n";
    cout <<"        3.Exit\n\n";
    cout << "Make your choise: ";
    Enter(choise);
    return choise;
}

int Enter(int &num)
{
for (;;)                                                        //
{                                                               //
    if (cin >> num) return num;                                 // Перевірка на правильність вводу
    cout <<"Invalid input!!!\n\a";                              //
    cin.clear();                                                //
    cin.ignore(numeric_limits<streamsize>::max(), '\n');        //
}
}

void Player::Throw(int dice_num,int roll_num)
{
    sum[roll_num]=0;
    for(int i=0;i<dice_num;i++)
    {
       int roll=(rand()%6+1);
       cout << roll<<' ';
       sum[roll_num]+=roll;
    }
    cout << "   : "<<sum[roll_num]<<endl;
}

