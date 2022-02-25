#include "Sorting.h"

template <typename T>
void Sorting<T>::SelectionSort(DynamicArray<T> *arr, int _size)
{
    int i, j, min_idx;
    for (i = 0; i < _size; i++)
    {
        min_idx = i;
        for (j = i + 1; j < _size; j++)
        {
            if ((*arr)[j] < (*arr)[min_idx])
                min_idx = j; // Find the index of minimum element
        }
        Swap(&(*arr)[i], &(*arr)[min_idx]);
    }
}
