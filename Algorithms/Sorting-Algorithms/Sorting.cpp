#include "Sorting.h"

template <typename T>
void Sorting<T>::swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}