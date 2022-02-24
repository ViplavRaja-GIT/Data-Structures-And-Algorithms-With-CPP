#include "HashTable.h"
template <typename T>
HashTable<T>::HashTable(int n) : count(0)
{
    this->size_ = n;
    this->table = new LinkedList<Item<T>>[n];
}

template <typename T>
int HashTable<T>::getHash(int key)
{
    return key % size_;
}

template <typename T>
void HashTable<T>::InsertElement(Item<T> *item)
{
    table[getHash(item->_key)].append(item);
    count++;
}

template <typename T>
Item<T> *HashTable<T>::GetElement(int key)
{
    Node<Item<T>> *itr = table[getHash(key)].getNth(0);
    while (itr->value->_key != key && itr->next != NULL)
    {
        itr = itr->next;
    }
    return itr->value;
}

template <typename T>
void HashTable<T>::RemoveElement(int key)
{
    Node<Item<T>> *head = table[getHash(key)].getNth(0);
    int index = 0;
    while (head->value->_key != key)
    {
        head = head->next;
        index++;
    }
    table[getHash(key)].removeNth(index);
    count--;
}

template <typename T>
int HashTable<T>::GetSize()
{
    return count;
}

template <typename T>
void HashTable<T>::DisplayHashTable()
{
    for (int i = 0; i < size_; i++)
    {
        cout << "| " << i << " | ";
        try // Empty check
        {
            Node<Item<T>> *itr = table[i].getNth(0);
            while (itr != NULL)
            {
                Item<T> *p = itr->value;
                cout << p->_value << " | ";
                itr = itr->next;
            }
            cout << endl;
        }
        catch (const std::exception &e)
        {
            // std::cerr << e.what() << '\n';
            cout << "|" << endl;
        }
    }
}