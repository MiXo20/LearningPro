#include <iostream>

using namespace std;

const size_t size=1000;

int main()
{
    char array1[size],array2[size],array3[size];
    size_t i=0,j=0;


    // Signs count

    cout << "Enter text 1: ";
    cin.getline(array1,size);
    while(array1[++i]);
      //  i++;
    cout << "Size: "<<i<< endl;

    // Compare

    cout << "Enter text 2: ";
    cin.getline(array2,size);
    i=0;
    do
    {
        if(array1[i]==array2[i])
        {
            i++;
            if(!(array1[i]||array2[i]))
            {
                cout <<"Equal.\n";
                break;
            }
        }
        else
        {
            cout <<"Not Equal.\n";
            break;
        }
    }
    while(i<size);
    i=0;

    //Search

    cout << "Signs for search: ";
    cin.getline(array3,size);
    do
    {
        if(array1[i]==array3[j])
        {
            if(!array3[j+1])  cout <<i-j+1<<' ';
            j++;
        }
        else j=0;
        i++;
    }
    while(array1[i]);

    return 0;
}
int *MySearch(int *res_arr, char *in_search_st)
{
    size_t size = 5, i=0, j=0, k=0;
    cout << "\nSigns to search: ";
    char *to_search_st = new char[size];
    to_search = StringEnter(to_search_st,size)
    do
    {
        if(in_st[i]==to_search_st[j])
        {
            if(!to_search_st[j+1])
            {
                res_arr[k]=i-j;
                k++;
            }
            j++;
        }
        else j=0;
        i++;
    }
    while(in_search_st[i]);
}
