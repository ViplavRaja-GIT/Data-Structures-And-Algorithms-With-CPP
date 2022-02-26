#include <iostream>
#include "../../Data-Structures/DynamicArray/DynamicArray.h"
#include "../Sorting-Algorithms/Sorting.h"
using namespace std;

template <typename T>
void ThreeSum(DynamicArray<T> *arr, int _size)
{
    Sorting<T> sort;
    sort.BubbleSort(arr, _size);
    for (int i = 0; i < _size; i++)
    {
        if (i != 0 && (*arr)[i] == (*arr)[i - 1])
            continue;
        int j = i + 1, k = _size - 1;
        while (j < k)
        {
            T sum = (*arr)[i] + (*arr)[j] + (*arr)[k];
            if(sum == 0)
            {
                cout<<"[ "<<(*arr)[i]<<", "<<(*arr)[j]<<", "<<(*arr)[k]<<"] ";
                j++;
                while (j < k && (*arr)[j] == (*arr)[j-1]) j++;
            }
            else if(sum > 0) k--;
            else j++;
        }
    }
}

int main()
{
    DynamicArray<int> dArray;
    dArray.add(-1);
    dArray.add(0);
    dArray.add(1);
    dArray.add(-2);
    dArray.add(2);
    dArray.add(-1);
    dArray.add(3);
    dArray.add(-4);
    cout << "Array :" << endl;
    dArray.print();
    cout << "\nPrinting Three Sum Elements :" << endl;
    ThreeSum<int>(&dArray, dArray.getSize());
    return 0;
}