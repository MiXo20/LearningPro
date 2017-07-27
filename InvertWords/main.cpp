#include <iostream>

using namespace std;

const size_t size=1000;

int main()
{
    char array[size], buf;

    cout <<"Enter text: ";
    cin.getline(array,size);

    size_t i=0,k=0;
    while(array[i])
    {
        i++;
        k++;
        if(array[i]==' '||!array[i])
        {
            for(size_t j=0;j<k/2;j++)
            {
                buf=array[i-k+j];
                array[i-k+j]=array[i-j-1];
                array[i-j-1]=buf;
            }
            k=-1;
        }
    }
    cout << array << endl;
    return 0;
}
