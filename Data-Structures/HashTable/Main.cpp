#include "HashTable.h"

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
    cout << "Fetched element key (5) : " << t->_value << endl;
    cout << "\nElement Count : " << h.GetSize() << endl;
    cout << "\nPrint HashTable." << endl;
    h.DisplayHashTable();
}