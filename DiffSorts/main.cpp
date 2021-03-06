#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void MyQsort(int* arr, size_t begin, size_t end);
int compare(const void *p1,const void *p2);
int BiSearch(const int *arr,const size_t arr_size, const int value);
void SelectionSort(int *arr,const size_t begin_indeks, const size_t end_indeks);

int main()
{
    int (*p) (const void *p1,const void *p2);
    p=compare;
    int begin,end;
    const size_t arr_size=400000000;
    int *arr= new int[arr_size];
    srand(time(0));
    for(size_t i=0;i<arr_size;++i)
    {
        arr[i]=rand()%100;
 //      cout << arr[i]<<' ';
    }
    cout << endl;
 //   cout << BiSearch(arr,arr_size, arr_size-1)<<endl;
 //   cout << arr[BiSearch(arr,arr_size, arr_size-1)];
    begin=clock();


    qsort(arr,arr_size,4,p);
    //SelectionSort(arr,0,arr_size-1);
    //MyQsort(arr,0,arr_size-1);

    end=clock();

 //   for(size_t i=0;i<arr_size;i++)
 //       cout << arr[i]<<' ';
    cout<<endl<<end-begin;
    delete[] arr;
    return 0;
}

int compare(const void *p1, const void *p2)
{
    return *(int*)p1-*(int*)p2;
}

void MyQsort(int *arr, size_t begin, size_t end)
{
    size_t right=end, left=begin;
    int median=*(arr+(begin+end)/2);
    while(left<=right)
    {
        while(*(arr+left)<median)
            left++;
        while(*(arr+right)>median)
            right--;
        if(left<=right)
        {
            int temp=*(arr+left);       //
            *(arr+left)=*(arr+right);   //  swap
            *(arr+right)=temp;          //
            left++;
            right--;
        }
    }
    if(begin<right) MyQsort(arr,begin,right);
    if(end>left) MyQsort(arr,left,end);
}

void SelectionSort(int *arr,const size_t begin_indeks, const size_t end_indeks)
{
    size_t begin=begin_indeks, end=end_indeks;
    while(begin!=end)
    {
        int min=arr[begin];
        for(size_t i=begin;i<=end;i++)
        {
            if(min>arr[i])
            {
                arr[begin]=arr[i];      //
                arr[i]=min;             //  swap
                min=arr[begin];         //
            }
        }
        begin++;
    }
}

int BiSearch(const int *arr,const size_t arr_size, const int value)
{
    size_t begin=0,end=arr_size-1;
    int s_value=*(arr+(begin+end)/2);
    while(begin<=end)
    {
        if(value>s_value)
        {
            begin=(begin+end)/2+1;
            s_value=*(arr+(begin+end)/2);
        }
        else
        if(value<s_value)
        {
            end=(begin+end)/2-1;
            s_value=*(arr+(begin+end)/2);
        }
        else
            return (begin+end)/2;
    }
    return -1;
}
