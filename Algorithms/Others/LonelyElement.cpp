#include "../Data-Structures/DynamicArray/DynamicArray.h"
#include <unordered_map>

/*
Every element which is equal to each other will have an XOR = 0. 
So if we take the XOR of all the elements all the elements will pair up and 
the Xor value will be the single integer value which is remaining. 
*/
template <typename T>
T SingleNumber(DynamicArray<T> &arr)
{
    int x = 0;
    for (int i = 0; i < arr.getSize(); i++)
    {
        x ^= arr[i];
    }
    return x;
}

/*
 We will traverse through the array and see if the particular element is 
 occuring once in the array and we do not have that element in the map
 then we will add that element to the map and if we have that element in
 the map then we will erase that element. If we do this thing for the entire
 array we will end up with only one element in end and that will be the
 lonely element in the array.
*/
template <typename T>
T SingleNumberUsingMap(DynamicArray<T> &arr)
{
    unordered_map<T,int> m;
    for(int i =0; i<arr.getSize();i++)
    {
        if(m.find(arr[i]) != m.end())
        {
            m.erase(arr[i]);
        } else {
            m[arr[i]]++;
        }
    };
    return m.begin()->first;
}

int main()
{
    DynamicArray<int> arr;
    arr.add(1);
    arr.add(1);
    arr.add(2);
    arr.add(2);
    arr.add(3);
    arr.add(3);
    arr.add(4);
    cout << "Array Elements." << endl;
    arr.print();
    cout << "Single Number : " << SingleNumber<int>(arr) << endl;
    cout << "Single Number Using Map: " << SingleNumberUsingMap<int>(arr) << endl;
    return 0;
}