#include "../Data-Structures/DynamicArray/DynamicArray.h"
using namespace std;

template <typename T>
T MaxSum(DynamicArray<T> *arr, int size)
{
    T max_in = (*arr)[0];
    T max_current = (*arr)[0];
    for (int i = 1; i < size; i++)
    {
        max_current = max((*arr)[i], max_current + (*arr)[i]);
        max_in = max(max_in, max_current);
    }
    return max_in;
}

int main()
{
    DynamicArray<int> dArray;
    dArray.add(1);
    dArray.add(2);
    dArray.add(3);
    dArray.add(4);
    dArray.add(5);
    dArray.add(-7);
    dArray.add(-9);
    dArray.add(6);
    cout << "KadanesAlgo" << endl;
    cout << "Printing Array" << endl;
    dArray.print();
    int data = MaxSum<int>(&dArray, dArray.getSize());
    cout << "Max Sum : " << data << endl;
    return 0;
}