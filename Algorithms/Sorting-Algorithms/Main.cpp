#include "Sorting.h"
#include <algorithm>

template <typename T>
void RandomiseTheArray(DynamicArray<T> *arr, int _size)
{
    random_shuffle(&(*arr)[0],&(*arr)[_size-1]);
}

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
    
    cout << "\nSorting :";
    dArray.print();
    sort.BubbleSort(&dArray, dArray.getSize());
    cout << "Bubble Sort Result :";
    dArray.print();
    
    RandomiseTheArray(&dArray, dArray.getSize());
    
    cout << "\nSorting :";
    dArray.print();
    sort.InsertionSort(&dArray, dArray.getSize());
    cout << "Insertion Sort Result :";
    dArray.print();
    
    RandomiseTheArray(&dArray, dArray.getSize());
    
    cout << "\nSorting :";
    dArray.print();
    sort.SelectionSort(&dArray, dArray.getSize());
    cout << "Selection Sort Result :";
    dArray.print();
    
    RandomiseTheArray(&dArray, dArray.getSize());
    
    cout << "\nSorting :";
    dArray.print();
    sort.ShellSort(&dArray, dArray.getSize());
    cout << "Shell Sort Result :";
    dArray.print();

    cout << endl;
    return 0;
}