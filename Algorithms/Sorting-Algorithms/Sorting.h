#include <iostream>
#include "../../Data-Structures/DynamicArray/DynamicArray.h"
using namespace std;

#ifndef SORTING
#define SORTING
template <typename T>
class Sorting
{
    public:
        void swap(T *x, T *y);
        void BubbleSort(DynamicArray<T> *arr, int _size);
        void InsertionSort(DynamicArray<T> *arr, int _size);  
};

#include "Sorting.cpp"
#endif