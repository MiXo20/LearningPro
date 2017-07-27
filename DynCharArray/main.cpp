#include "arrays.h"

using namespace std;


int main()
{
    size_t size1=5, size2=5;
    char *str1, *str2, *str3;
    str1=new char[size1];
    str2=new char[size2];

    cout << "Enter str1: ";
    str1=StringEnter(str1,size1);
    cout <<"Str1 length: "<<MyStrLen(str1);

    cout << "\nEnter str2: ";
    str2=StringEnter(str2,size2);
    cout <<"Str2 length: "<<MyStrLen(str2);

    str3=new char [size1+size2];

    MyStrCpy(str1,str2,str3);
    cout << "\nStr3: "<<str3;
    cout << "\nStr3 length: "<<MyStrLen(str3);
    cout << "\nStr1=Str2 ?: "<<MyStrCmp(str1,str2);

    delete[] str1;
    delete[] str2;
    delete[] str3;

    return 0;
}


