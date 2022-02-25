#include "Sorting.h"

template <typename T>
void Sorting<T>::swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

template <typename T>
void Sorting<T>::BubbleSort(DynamicArray<T> *arr, int _size)
{
    int i, j;
    for (i = 0; i < _size - 1; i++)
        // Last i elements are already in place
        for (j = 0; j < _size - i - 1; j++)
            // swap if arr[j] is greater than arr[j+1]
            if ((*arr)[j] > (*arr)[j + 1])
            {
                swap(&(*arr)[j], &(*arr)[j + 1]);
            }
}

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
