#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int *ArrOversize(size_t &size, int *arr);

int main()
{
    srand(time(0));

    size_t count = 0, size=5;
    int *arr;
    arr = new int [size];
    do
    {
        cin >> arr[count];
        //arr[count]=rand();
        count++;
        if(count==size)
        {
         arr = ArrOversize(size, arr);
        }
    }
    while(arr[count-1]);
    for(size_t i=count;i;i--)
        cout << arr[i-1]<<' ';
    cout << endl;
    cout << "Numbers count: "<<count <<' '<<"Array size: "<<size<<endl;
    delete[] arr;
    //system("pause");
    return 0;
}
int *ArrOversize(size_t &size, int *arr)
{
    int *new_arr;
    new_arr = new int [size+5];
    for(size_t i=0;i<size;i++)
        new_arr[i]=arr[i];
    delete[] arr;
    arr = new int [size+5];
    for(size_t i=0;i<size;i++)
        arr[i]=new_arr[i];
    //arr=new_arr;                 ?
    delete[] new_arr;
    size=size+5;
    return arr;
}
