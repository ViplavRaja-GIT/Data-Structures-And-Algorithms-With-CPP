#include "Sorting.h"

/*
Input data: 4, 10, 3, 5, 1
         4(0)
        /   \
     10(1)   3(2)
    /   \
 5(3)    1(4)
The numbers in bracket represent the indices in the array 
representation of data.
Applying heapify procedure to index 1:
         4(0)
        /   \
    10(1)    3(2)
    /   \
5(3)    1(4)
Applying heapify procedure to index 0:
        10(0)
        /  \
     5(1)  3(2)
    /   \
 4(3)    1(4)
The heapify procedure calls itself recursively to build heap
 in top down manner.
*/


template <typename T>
void Sorting<T>::Heapify(DynamicArray<T> *arr, int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && (*arr)[l] > (*arr)[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && (*arr)[r] > (*arr)[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        Swap(&(*arr)[i], &(*arr)[largest]);

        // Recursively heapify the affected sub-tree
        Heapify(arr, n, largest);
    }
}

template <typename T>
void Sorting<T>::HeapSort(DynamicArray<T> *arr, int _size)
{
    // Build heap (rearrange array)
    for (int i = _size / 2 - 1; i >= 0; i--)
        Heapify(arr, _size, i);

    // One by one extract an element from heap
    for (int i = _size - 1; i > 0; i--)
    {
        // Move current root to end
        Swap(&(*arr)[0], &(*arr)[i]);

        // call max heapify on the reduced heap
        Heapify(arr, i, 0);
    }
}