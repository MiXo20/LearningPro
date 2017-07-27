#include "fraction.h"
#include <conio.h>

int menu();
int demo();

int main()
{
    for(size_t i=0;i=menu();)
    {
        switch (i) {
        case 1:
        {
            for(size_t i=0;i=demo();)
            {
                system("cls");
                switch(i){
                case 1:
                {
                    Fraction a,b;
                    cout << "Enter a: ";
                    cin >> a;
                    cout << "Enter b: ";
                    cin >> b;
                    a+=b;
                    cout << "a+=b :";
                    cout <<a<<endl;
                    while(!kbhit());
                    break;
                }
                case 2:
                {
                    Fraction a,b;
                    cout << "Enter a: ";
                    cin >> a;
                    cout << "Enter b: ";
                    cin >> b;
                    a-=b;
                    cout << "a-=b :";
                    cout <<a<<endl;
                    while(!kbhit());
                    break;
                }
                case 3:
                {
                    Fraction a,b;
                    cout << "Enter a: ";
                    cin >> a;
                    cout << "Enter b: ";
                    cin >> b;
                    a*=b;
                    cout << "a*=b :";
                    cout <<a<<endl;
                    while(!kbhit());
                    break;
                }
                case 4:
                {
                    Fraction a,b;
                    cout << "Enter a: ";
                    cin >> a;
                    cout << "Enter b: ";
                    cin >> b;
                    a/=b;
                    cout << "a/=b :";
                    cout <<a<<endl;
                    while(!kbhit());
                    break;
                }
                while(!kbhit());
                break;
                case 5:
                {
                    Fraction a,b,c;
                    cout << "Enter a: ";
                    cin >> a;
                    cout << "Enter b: ";
                    cin >> b;
                    c=a+b;
                    cout << "c=a+b= ";
                    cout << c <<endl;
                    while(!kbhit());
                    break;
                }
                case 6:
                {
                    Fraction a,b,c;
                    cout << "Enter a: ";
                    cin >> a;
                    cout << "Enter b: ";
                    cin >> b;
                    c=a-b;
                    cout << "c=a-b= ";
                    cout << c <<endl;
                    while(!kbhit());
                    break;
                }
                case 7:
                {
                    Fraction a,b,c;
                    cout << "Enter a: ";
                    cin >> a;
                    cout << "Enter b: ";
                    cin >> b;
                    c=a*b;
                    cout << "c=a*b= ";
                    cout << c <<endl;
                    while(!kbhit());
                    break;
                }
                case 8:
                {
                    Fraction a,b,c;
                    cout << "Enter a: ";
                    cin >> a;
                    cout << "Enter b: ";
                    cin >> b;
                    c=a/b;
                    cout << "c=a/b= ";
                    cout << c <<endl;
                    while(!kbhit());
                    break;
                }
                default:
                    break;
                }
            }
            break;
        }
        case 2:
        {
            Fraction S,b1,q;
            size_t N;
            system("cls");
            cout << "Geometric Sequence\n";
            cout << "Enter b1: ";
            cin >>b1;
            cout << "Enter q: ";
            cin >> q;
            cout << "Enter elements count N: ";
            cin >> N;
            S=b1*((1-q.Fpow(N))/(1-q));
            cout <<"S(N) = "<< S <<endl;
            while(!kbhit());
            break;
        }
        default:
            break;
        }
    }
    return 0;
}

int menu()
{
    for(;;)
    {
        size_t i=0;
        system("cls");
        cout << " Fraction Class Operation\n";
        cout << "1. Class Demo\n";
        cout << "2. Geometric Sequence Sum\n";
        cout << "0. Exit\n\n";
        cout << "Enter menu item : ";
        if(cin >> i) return i;
        else
        {
            cin.clear();
            cin.ignore(500,'\n');
        }
    }
}

int demo()
{
    for(;;)
    {
        size_t i=0;
        system("cls");
        cout << " Fraction Demo\n";
        cout <<"Choose operation\n";
        cout << "1. Fraction += Fraction\n";
        cout << "2. Fraction -= Fraction\n";
        cout << "3. Fraction *= Fraction\n";
        cout << "4. Fraction /= Fraction\n";
        cout << "5. Fraction = Fraction + Fraction\n";
        cout << "6. Fraction = Fraction - Fraction\n";
        cout << "7. Fraction = Fraction * Fraction\n";
        cout << "8. Fraction = Fraction / Fraction\n";
        cout << "0. Main menu\n";
        cout << "Enter menu item : ";
        if(cin >> i) return i;
        else
        {
            cin.clear();
            cin.ignore(500,'\n');
        }
    }
}
