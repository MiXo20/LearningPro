#ifndef TEMPLATEVECTOR_H
#define TEMPLATEVECTOR_H
#include <iostream>

template <typename T>
class MyVector
{
    T *vector;
    size_t size;
    size_t capasity;

public:
    MyVector();
    MyVector(size_t s, T &value);
    MyVector(const MyVector &v);
    ~MyVector() {delete [] vector;}

    T& at(size_t i);
    T at(size_t i) const;
    size_t Size() const;
    void push_back(const T &value);
    T& operator [] (size_t i);
    T operator [] (size_t i) const;
    MyVector<T> &operator =(const MyVector &v);
    bool operator == ( const MyVector &b) const;
    void resize(size_t new_size);
};

template <typename T> MyVector<T>::MyVector()
{
    vector= new T[size=0];
    capasity=size;
}

template <typename T> MyVector<T>::MyVector(size_t s, T &value)
{
    vector = new T[size=s];
    for(size_t i=0;i<size;i++)
        vector[i]=value;
    capasity=size;
}

template <typename T> MyVector<T>::MyVector(const MyVector &v)
{
    vector = new T [size=v.Size()];
    for(size_t i=0;i<size;i++)
    vector[i]=v.at(i);
    capasity=size;
}

template <typename T> T &MyVector<T>::at(size_t i)
{
    if(i<size)
        return vector[i];
    else
        throw std::out_of_range("Index Error");
}

template <typename T> T MyVector<T>::at(size_t i) const
{
    if(i<size)
        return vector[i];
    else
        throw std::out_of_range("Index Error");
}

template <typename T> size_t MyVector<T>::Size() const
{
    return this->size;
}

template <typename T> void MyVector<T>::push_back(const T &value)
{
    resize(size+1);
    vector[size-1]=value;
}

template <typename T> T &MyVector<T>::operator [](size_t i)
{
    return vector[i];
}

template <typename T> T MyVector<T>::operator [](size_t i) const
{
    return vector[i];
}

template <typename T> MyVector<T>& MyVector<T>::operator = (const MyVector &v)
{
    T *temp= new T [this->size=v.Size()];
    for(size_t i=0;i<size;i++)
        temp[i]=v[i];
    delete[] vector;
    vector=temp;
    return *this;
}

template <typename T> bool MyVector<T>::operator == ( const MyVector &b) const
{
    if( size != b.Size()) return false;
    for(size_t i=0; this->at(i)==b.at(i); i++)
        if(i==(b.Size()-1)) return true;
    return false;
}

template <typename T> void MyVector<T>::resize(size_t new_size)
{
    T *temp=new T [new_size];
    for(size_t i=0;i<size;i++)
        temp[i]=vector[i];
    delete[] vector;
    vector=temp;
    size=new_size;
    capasity=size;
}


#endif // TEMPLATEVECTOR_H
