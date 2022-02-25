#include "Sorting.h"

template <typename T>
void Sorting<T>::Swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}