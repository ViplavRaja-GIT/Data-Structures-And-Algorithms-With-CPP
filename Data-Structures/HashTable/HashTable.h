#include <string.h>
#include "../LinkedList/LinkedList.h"
using namespace std;

#ifndef HASHTABLE
#define HASHTABLE

template <typename T>
class Item
{
public:
    int _key;
    T _value;
    Item(int key_, T value_)
    {
        this->_key = key_;
        this->_value = value_;
    }
};

template <typename T>
class HashTable
{
private:
    int size_;
    LinkedList<Item<T>> *table;
    int getHash(int key)
    {
        return key % size_;
    }

public:
    HashTable(int n);
    void InsertElement(Item<T> *item);
    Item<T>* GetElement(int key);
    void RemoveElement(int key);
    void DisplayHashTable();
};

#include "HashTable.cpp"
#endif