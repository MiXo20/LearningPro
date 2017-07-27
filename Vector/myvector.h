#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream> 

class MyVector
{
    double *vector;
    size_t size;
    size_t capasity;

public:
    MyVector(size_t s);
    MyVector(const MyVector &v);
    ~MyVector() {delete [] vector;}

    double& at(size_t i);
    double at(size_t i) const;
    size_t Size() const;
    void push_back(const double value);
    double& operator [] (size_t i);
    double operator [] (size_t i) const;
    MyVector& operator = (const MyVector &v);
    bool operator == ( const MyVector &b) const;
    void resize(size_t new_size);
};
#endif // MYVECTOR_H
