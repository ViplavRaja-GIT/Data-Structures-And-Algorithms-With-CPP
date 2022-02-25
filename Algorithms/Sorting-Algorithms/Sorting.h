#include <iostream>
#include "../../Data-Structures/DynamicArray/DynamicArray.h"
using namespace std;

#ifndef SORTING
#define SORTING
template <typename T>
class Sorting
{
    public:
        void Swap(T *x, T *y);
        void BubbleSort(DynamicArray<T> *arr, int _size);
        void InsertionSort(DynamicArray<T> *arr, int _size);
        void SelectionSort(DynamicArray<T> *arr, int _size);
        void ShellSort(DynamicArray<T> *arr, int _size);
};

#include "Sorting.cpp"
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
#include "SelectionSort.cpp"
#include "ShellSort.cpp"
#endif