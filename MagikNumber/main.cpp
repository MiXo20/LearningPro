#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main()
{
    int player_num, prev_num=0, count=0;
    unsigned int random_num;

    srand(time(0));
    random_num = rand()%100+1;
    cout << "Try to gues the number from 1 to 100?\n";

    while(true)
    {
        count++;
        for (;;)                                                        //
        {                                                               //
            cout << "Magic Number is  ";                                //  Перевірка на правильність вводу
            if (cin >> player_num) break;                               //
            cout <<"Invalid input!!!\n\a";                              //
            cin.clear();                                                //
            cin.ignore(numeric_limits<streamsize>::max(), '\n');        //
        }                                                               //
        if (random_num == player_num)
        {
            cout << "You are right!!!\n";
            cout << "It was " << count << " atempt!\n";
            break;
        }
        else
        {
            if(player_num<=prev_num&&prev_num<random_num&&prev_num)
            {
                cout << "Uh... Biger, I told you!!!\n";
            }
            else
            if(player_num>=prev_num&&prev_num>random_num&&prev_num)
            {
                cout << "Uh... Smaler, I told you!!!\n";
            }
            else
            {
                if (player_num > random_num)
                    cout << "The number is smaller.\n";
                else
                    cout << "The number is biger.\n";
                prev_num=player_num;
            }
        }
    }
    system("pause");
return 0;
}
