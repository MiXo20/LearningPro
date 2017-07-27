#include <iostream>

using namespace std;

size_t StrLen (const char *str1);
char* StrCpy(char *str1, const char *str2);
bool StrCmp(const char *str1, const char *str2);


class MyString
{

    char *str;
    size_t size;

    void ChangeSize(size_t new_size);

public:
    MyString(const char *str0="");
   // MyString() : MyString(const char *str0);
    MyString(const MyString &a);


    ~MyString()    {delete[] str;}

    inline size_t length() {return StrLen(str);}
    inline size_t GetSize() {return size;}
    inline char* GetStr() {return str;}

    char& operator [](size_t i) ;
    const char& operator [](size_t i) const;

    MyString& operator += (const MyString &b);
    bool operator == (const MyString &b) const;
    MyString& operator = (const MyString &a);


    friend istream& operator >> (istream &is, MyString &a);
    friend ostream& operator << (ostream &os, const MyString &a);
};

    MyString operator + (const MyString &a, const MyString &b);

int main()
{

    MyString a("Hello"),c(" World!");
    cout << a+c<<endl;
    for(size_t i=0;i<a.length();i++)
        cout <<a[i];
    return 0;
}

MyString :: MyString (const char *str0)
{
    str = new char[size=StrLen(str0)+1];
    StrCpy(str,str0);
}

MyString:: MyString(const MyString &a)
{
    str=new char[a.size];
    size=a.size;
    StrCpy(str,a.str);
}

istream& operator >> (istream &is, MyString &a)
{
    for(size_t i=0;;i++)
    {
        a.str[i]=is.get();
        if(i==a.size-1)
            a.ChangeSize(5);
        if(is.peek()=='\n')
        {
            a.str[i+1]='\0';
            is.ignore();
            break;
        }
    }
    return is;
}

ostream& operator << (ostream &os, const MyString &a)
{
    os << a.str;
    return os;
}

char& MyString::operator [](size_t i)
{
    return str[i];
}

const char& MyString::operator [](size_t i) const
{
    return str[i];
}

MyString& MyString::operator += (const MyString &b)
{
    char *temp;
    temp=new char [StrLen(str)+StrLen(b.str)+1];
    size_t i=0,j=0;
    while(str[i])
    {
        temp[i]=str[i];
        i++;
    }
    while(b.str[j])
    {
        temp[i]=b.str[j];
        i++;
        j++;
    }
    temp[i]='\0';
    delete [] str;
    str=temp;
    size=StrLen(str)+1;
    return *this;
}

MyString operator + (const MyString &a,const MyString &b)
{
    MyString temp=a;
    return temp+=b;
}

MyString& MyString::operator = (const MyString &a)
{
    str=new char[a.size];
    size=a.size;
    StrCpy(str,a.str);
    return *this;
}

bool MyString::operator == (const MyString &b) const
{
    return StrCmp( str, b.str);
}

void MyString::ChangeSize(size_t new_size)
{
    char *new_str;
    new_str = new char [size+new_size];          //зауваження передаємо не дельту а новий розмір повністю
    StrCpy(new_str,str);
    delete[] str;
    str=new_str;
    size=size+new_size;
}


size_t StrLen (const char *str1)
{
    size_t i=0;
    for(i=0;str1[i];i++);
    return i;
}

char* StrCpy(char *str1, const char *str2)
{
    for (size_t i=0; i<=(StrLen(str2)); i++)
    {
            str1[i] = str2[i];
    }
    return str1;
}

bool StrCmp(const char *str1, const char *str2)
{
    for(size_t i=0; str1[i]==str2[i]; i++ )
    {
        if(!str1[i]&&!str2[i])
        return true;
    }
    return false;
}
