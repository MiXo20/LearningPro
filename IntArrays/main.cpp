#include <iostream>

using namespace std;

const size_t size=8;

int main()
{
    // EvenNum invertion

    int array[8],buf;
    for(size_t i=0; i<size; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> array[i];
    }
    for(size_t i=1; i<size; i+=2)
    {
        buf=array[i-1];
        array[i-1]=array[i];
        array[i]=buf;
    }
    for(size_t i=0; i<size; i++)
        cout <<array[i]<< ' ';
    cout<<endl;

    // Bubble Sort

    for(size_t i=0;i<size; i++)
    {
        for(size_t j=0;j<size; j++)
            if(array[i]>array[j])
            {
                buf=array[i];
                array[i]=array[j];
                array[j]=buf;
            }
    }
    for(size_t i=0; i<size; i++)
        cout <<array[i]<< ' ';
    cout <<endl;

    // Search
    int search_num;
    cout << "Search for ";
    cin >> search_num;
    for(size_t i=0; i<size; i++)
    {
        if(array[i]==search_num)
        {
            cout << "Found\n";
            break;
        }
        if(i==size-1) cout << "Not Found\n";
    }
    return 0;
}
