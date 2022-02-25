#include <iostream>
#include <assert.h>
using namespace std;

#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY
template <typename T>
class DynamicArray
{
private:
    int size_;
    int max_;
    T *arrayHolder_;

public:
    DynamicArray();
    int getSize();
    T &operator[](int index);
    void add(T value);
    void print();
    ~DynamicArray();
};
#include "DynamicArray.cpp"
#endif