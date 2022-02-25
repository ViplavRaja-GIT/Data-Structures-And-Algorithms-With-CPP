#include "Sorting.h"

// #Insertion_Sort
template <typename T>
void Sorting<T>::InsertionSort(DynamicArray<T> *arr, int _size)
{
    int i, j;
    T key;
    for (i = 1; i < _size; i++)
    {
        key = (*arr)[i];
        j = i - 1;
        while (j >= 0 && (*arr)[j] > key)
        {
            (*arr)[j + 1] = (*arr)[j];
            j = j - 1;
        }
        (*arr)[j + 1] = key;
    }
}