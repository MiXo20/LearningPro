#include <iostream>
#include "myvector.h"

MyVector::MyVector(size_t s)
{
    vector = new double [size=s];
    for(size_t i=0;i<size;i++)
        vector[i]=0;
    capasity=size;
}

MyVector::MyVector(const MyVector &v)
{
    vector = new double [size=v.Size()];
    for(size_t i=0;i<size;i++)
    vector[i]=v.at(i);
    capasity=size;
}            

double& MyVector::at(size_t i)
{
    if(i<size)
        return vector[i];
    else
        throw std::out_of_range("Index Error");
}

double MyVector::at(size_t i) const
{
    if(i<size)
        return vector[i];
    else
        throw std::out_of_range("Index Error");
}

size_t MyVector::Size() const
{
    return this->size;
}

void MyVector::push_back(const double value)
{
    resize(size+1);
    vector[size-1]=value;
}

double& MyVector::operator [] (size_t i)
{
    return vector[i];
}

double MyVector::operator [] (size_t i) const
{
    return vector[i];
}

MyVector& MyVector::operator = (const MyVector &v)
{
    double *temp= new double [this->size=v.Size()];
    for(size_t i=0;i<size;i++)
        temp[i]=v[i];
    delete[] vector;
    vector=temp;
    return *this;
}

bool MyVector::operator == ( const MyVector &b) const
{
    if( size != b.Size()) return false;
    for(size_t i=0; this->at(i)==b.at(i); i++)
        if(i==(b.Size()-1)) return true;
    return false;
}

void MyVector::resize(size_t new_size)
{
    double *temp=new double [new_size];
    for(size_t i=0;i<size;i++)
        temp[i]=vector[i];
    delete[] vector;
    vector=temp;
    size=new_size;
    capasity=size;
}
