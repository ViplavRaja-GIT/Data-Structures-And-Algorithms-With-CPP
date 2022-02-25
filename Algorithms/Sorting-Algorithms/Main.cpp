#include "Sorting.h"

int main()
{
    DynamicArray<int> dArray;
    dArray.add(3);
    dArray.add(4);
    dArray.add(1);
    dArray.add(99);
    dArray.add(54);
    dArray.add(47);
    dArray.add(33);
    dArray.add(-89);
    dArray.add(-78);
    Sorting<int> sort;
    sort.BubbleSort(&dArray, dArray.getSize());
    sort.InsertionSort(&dArray, dArray.getSize());
    dArray.print();
    return 0;
}