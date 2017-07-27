#include <iostream>


char *ArrOversize(char *arr, size_t &size)      // змінює розмір динамічного масиву
{
    char *new_arr;
    new_arr = new char [size+5];
    for(size_t i=0;i<size;i++)
        new_arr[i]=arr[i];
    delete[] arr;
    //arr = new char [size+5];                  1
    //for(size_t i=0;i<size;i++)                2 тут була помилка!!!!
     //   arr[i]=new_arr[i];                    3
    arr=new_arr;
    //delete[] new_arr;                         4
    size=size+5;
    return arr;
}

char *StringEnter(char *p, size_t &size)        // посимвольно зчитує стрічку в динамічний масив
{
    int c;
    size_t count = 0;
    //p=new char[size];
    for(;;)
    {
        c = getchar();
        if(c==10)
        {
            p[count]=0;
            break;
        }

        p[count]=static_cast<char>(c);
        ++count;
        if(count==size)
        {
            p = ArrOversize(p, size);
        }
    }
    return p;
}

void MyStrCpy(const char *st1, const char *st2, char *st3)  // копіює st1 та st2 в st3
{
    size_t i=0,j=0;
    while(st1[i])
    {
        st3[i]=st1[i];
        i++;
    }
    while(st2[j-1])
    {
        st3[i]=st2[j];
        i++;
        j++;
    }
}

size_t MyStrLen(const char *st)                               // довжина стрічки
{
    size_t i=0;
    for(i=0;st[i];i++);
    return i;
}

bool MyStrCmp(const char *st2, const char *st1)           // порівняння стрічок
{
    for(size_t i=0; st1[i]==st2[i]; i++ )
    {
        if(!st1[i]&&!st2[i])
        return true;
    }
        return false;
}

