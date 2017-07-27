#include <iostream>

using namespace std;

int main()
{
    for(int i=0; i<=20; i++)
    {
        i+=i%2;
        cout <<i<<' ';
    }
    cout<<endl;

    int a,b;
    cout << "Enter a,b  (a<b): \n";
    cin >>a >> b;
    do
    {
       if(!(a%2)) cout << a <<' ';
       a++;
    }
    while(a<=b);
    return 0;
}
