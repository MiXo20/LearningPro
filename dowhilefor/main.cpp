#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    for(int i=1;i<6;i++) cout <<i<<' ';
    int i=5;
    while(i)
    {
        cout <<i<<' ';
        i--;
    }
    do
    {
        i++;
        cout <<i<<' ';
    }
    while(i<5);
    return 0;
}
