#include <iostream>
#include "fraction.h"
#include "templatevector.h"

using namespace std;

int main()
{
    Fraction f(1,2);
    MyVector<Fraction> d(10,f),x;
    MyVector<MyVector<Fraction> > c(6,d);
    MyVector<MyVector<int> > a,b;

    x=c.at(5);

    for(size_t i=0; i<x.Size();i++)
        cout << x[i];

    return 0;
}
