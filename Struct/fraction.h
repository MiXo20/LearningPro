#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>

using namespace std;

class Fraction
{

    int chasel;
    int denominator;

public:
    Fraction (int ch , int den = 1) {chasel=ch; denominator=den;}
    Fraction () {chasel=0;denominator=1;}

    Fraction &operator += (const Fraction &b);
    Fraction &operator -= (const Fraction &b);
    Fraction &operator *= (const Fraction &b);
    Fraction &operator /= (const Fraction &b);
    Fraction operator -() const;

    bool operator > (const Fraction &a) const;
    bool operator > (const int a) const;
    bool operator < (const Fraction &a) const;
    bool operator < (const int a) const;
    bool operator == (const Fraction &a) const;
    bool operator == (const int a) const;

    friend bool operator > (const int a, const Fraction &b);
    friend bool operator < (const int a, const Fraction &b);
    friend bool operator == (const int a, const Fraction &b);

    void Display();
    int GetChasel() {return chasel;}
    int GetDenominator() {return denominator;}
    void PutChasel(int ch) {chasel=ch;}
    void PutDenominator(int den) {denominator=den;}
    Fraction Fpow(const int n) const;
    Fraction Fabs() const;

    friend Fraction operator + (const Fraction &a,const Fraction &b);
    friend Fraction operator - (const Fraction &a,const Fraction &b);
    friend Fraction operator * (const Fraction &a,const Fraction &b);
    friend Fraction operator / (const Fraction &a,const Fraction &b);

    //friend Fraction operator - (const int a, const Fraction &b);
    //friend Fraction operator - (const Fraction &b, const int a);

    friend ostream & operator << (ostream &os, const Fraction &a);
    friend istream & operator >> (istream &is, Fraction &p);
};

int NSD(int ch, int den);

#endif // FRACTION_H
