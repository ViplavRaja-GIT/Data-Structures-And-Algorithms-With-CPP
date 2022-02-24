#include <string.h>
#include <typeinfo>
#include "../LinkedList/LinkedList.h"
using namespace std;

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
    HashTable(int n)
    {
        this->size_ = n;
        this->table = new LinkedList<Item<T>>[n];
    }

    void InsertElement(Item<T> *item)
    {
        table[getHash(item->_key)].append(item);
    }

    Item<T>* GetElement(int key)
    {
        Node<Item<T>> *itr = table[getHash(key)].getNth(0);
        while(itr->value->_key != key && itr->next != NULL)
        {
            itr = itr->next;
        }
        return itr->value;
    }

    void RemoveElement(int key)
    {
        Node<Item<T>> *head = table[getHash(key)].getNth(0);
        int index = 0;
        while(head->value->_key != key)
        {
            head = head->next;
            index++;
        }
        cout << "\nIndex" << index << endl;
        table[getHash(key)].removeNth(index);
    }

    void DisplayHashTable()
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
            catch(const std::exception& e)
            {
                // std::cerr << e.what() << '\n';
                cout << "|" << endl;
            }
        }
    }
};

int main()
{
    HashTable<string> h(5);
    h.InsertElement(new Item<string>(5, "James"));
    h.InsertElement(new Item<string>(10, "Robert"));
    h.InsertElement(new Item<string>(15, "John"));
    h.InsertElement(new Item<string>(3, "Michael"));
    h.InsertElement(new Item<string>(2, "William"));
    h.InsertElement(new Item<string>(4, "David"));
    h.InsertElement(new Item<string>(7, "Richard"));
    h.InsertElement(new Item<string>(9, "Joseph"));
    h.InsertElement(new Item<string>(11, "Thomas"));
    h.RemoveElement(11);

    cout << "Get element from HashTable." << endl;
    Item<string> *t = h.GetElement(5);
    cout << t->_value << endl;
    cout << "\nPrint HashTable." << endl;
    h.DisplayHashTable();
}