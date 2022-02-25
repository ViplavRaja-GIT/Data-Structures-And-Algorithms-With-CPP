#include "Sorting.h"

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