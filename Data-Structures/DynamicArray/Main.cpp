#include "DynamicArray.h"
int main(int argc, char **argv)
{
    DynamicArray<int> dArray;
    cout << "Addding 20 elements in Array" << endl;
    for (size_t i = 0; i < 20; i++)
    {
        dArray.add(i);
    }
    cout << "Last element : " << dArray[19] << endl;
    cout << "Array size_ : " << dArray.getSize() << endl;
    cout << "Print Array" << endl;
    dArray.print();
    return 0;
}