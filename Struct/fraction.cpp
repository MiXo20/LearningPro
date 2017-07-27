#include "fraction.h"

void Fraction::Display()
{
    if(chasel==1)
        cout <<chasel/NSD(chasel, denominator)<<' ';
    else
        cout << chasel/NSD(chasel, denominator)<<'/'<<denominator/NSD(chasel, denominator)<<' ';
}

int NSD(int ch, int den)
{
    if(den==0)
        return abs(ch);
    else
        return NSD(abs(den),abs(ch%den));
}

Fraction operator + (const Fraction &a,const Fraction &b)
{
    Fraction c;
    c.chasel=a.chasel*b.denominator+a.denominator*b.chasel;
    c.denominator=a.denominator*b.denominator;
    return c;
}


Fraction &Fraction::operator +=(const Fraction &b)
{
    chasel=chasel*b.denominator+(denominator*b.chasel);
    denominator=denominator*b.denominator;
    return *this;
}

Fraction operator - (const Fraction &a,const Fraction &b)
{
    Fraction c;
    c.chasel=a.chasel*b.denominator-a.denominator*b.chasel;
    if(c.chasel==0)
        c.denominator=1;
    else
        c.denominator=a.denominator*b.denominator;
    return c;
}

//Fraction operator - (const int a, const Fraction &b)
//{
//    Fraction res;
//    res.chasel=a*b.denominator-b.chasel;
//    if (res.chasel==0)
//        res.denominator=1;
//    else
//        res.denominator=b.denominator;
//    return res;
//}

//Fraction operator - (const Fraction &b, const int a)
//{
//    Fraction res;
//    res.chasel=b.chasel-a*b.denominator;
//    if (res.chasel==0)
//        res.denominator=1;
//    else
//        res.denominator=b.denominator;
//    return res;
//}

Fraction& Fraction::operator -=(const Fraction &b)
{
    chasel=chasel*b.denominator-denominator*b.chasel;
    if(chasel==0)
        denominator=1;
    else
        denominator=denominator*b.denominator;
    return *this;
}

Fraction operator * (const Fraction &a,const Fraction &b)
{
    Fraction c;
    c.chasel=a.chasel*b.chasel;
    c.denominator=a.denominator*b.denominator;
    return c;
}

Fraction& Fraction::operator *=(const Fraction &b)
{
    chasel=chasel*b.chasel;
    denominator=denominator*b.denominator;
    return *this;
}

Fraction operator / (const Fraction &a, const Fraction &b)
{
    Fraction c;
    c.chasel=a.chasel*b.denominator;
    c.denominator=a.denominator*b.chasel;
    if(c.chasel<0&&c.denominator<0)
        return c.Fabs();
    else if(c.denominator<0&&c.chasel>0)
        {
            c.chasel=-c.chasel;
            c.denominator=abs(c.denominator);
            return c;
        }
    return c;
}

Fraction& Fraction::operator /= (const Fraction &b)
{
    chasel=chasel*b.denominator;
    denominator=denominator*b.chasel;
    if(chasel<0&&denominator<0)
        return *this=this->Fabs();
    else
        if(denominator<0&&chasel>0)
        {
            chasel=-chasel;
            denominator=abs(denominator);
            return *this;
        }
    return *this;
}



Fraction Fraction::operator - () const
{
    Fraction b(*this);
    b.chasel=-b.chasel;
    return b;
}

Fraction Fraction::Fpow(const int n) const
{
    Fraction res;
    res.chasel=pow(chasel,n);
    res.denominator=pow(denominator,n);
    return res;
}

Fraction Fraction::Fabs() const
{
    Fraction res;
    res.chasel=abs(chasel);
    res.denominator=abs(denominator);
    return res;
}



bool Fraction::operator > (const Fraction &a) const
{
    if(chasel*a.denominator>a.chasel*denominator)
        return true;
    return false;
}

bool Fraction::operator > (const int a) const
{
    if(chasel>a*denominator)
        return true;
    return false;
}

bool operator > (const int a, const Fraction &b)
{
    if(a*b.denominator>b.chasel)
        return true;
    return false;
}



bool Fraction::operator < (const Fraction &a) const
{
    if(chasel*a.denominator<a.chasel*denominator)
        return true;
    return false;
}

bool Fraction::operator < (const int a) const
{
    if(chasel<a*denominator)
        return true;
    return false;
}

bool operator < (const int a, const Fraction &b)
{
    if(a*b.denominator<b.chasel)
        return true;
    return false;
}



bool Fraction::operator == (const Fraction &a) const
{
    return chasel*a.denominator==a.chasel*denominator;
}

bool Fraction::operator == (const int a) const
{
    return chasel==a*denominator;
}

bool operator == (const int a,const Fraction &b)
{
    return a*b.denominator==b.chasel;
}



ostream& operator << (ostream &os, const Fraction &a)
{
    if(a.chasel==0)
    {
        os <<a.chasel<<'/'<<1;
        return os;
    }
    else
    {
        os << a.chasel/NSD(a.chasel, a.denominator)<<'/'<<a.denominator/NSD(a.chasel, a.denominator);
        return os;
    }
}

istream& operator >> (istream &is, Fraction &p)
{

    for(;;)
    {
        if(is>>p.chasel)
        {
            if(is.peek()=='/')
            {
                is.ignore(1);
                if(is>>p.denominator)
                {
                    if(p.denominator<0)
                    {
                        p.chasel=-p.chasel;
                        p.denominator=-p.denominator;
                    }
                    return is;
                }
                else
                {
                    is.clear();
                    is.ignore(500,'\n');
                }
            }
            else
                if(is.peek()=='\n')
                {
                    p.denominator=1;
                    return is;
                }
                else
                {
                    is.clear();
                    is.ignore(500,'\n');
                }
        }
        else
        {
            is.clear();
            is.ignore(500,'\n');
        }
        cout << "Bad input!!!\n";
    }
}

