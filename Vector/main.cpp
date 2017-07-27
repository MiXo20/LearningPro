#include <iostream>
#include "myvector.h"

using namespace std;

int main()
{
    MyVector a(0), c(10);
    for(size_t i=0;i<15;i++)
        a.push_back(1);
    c=a;
    for(size_t i=0;i<c.Size();i++)
        cout << a[i];

    return 0;
}
