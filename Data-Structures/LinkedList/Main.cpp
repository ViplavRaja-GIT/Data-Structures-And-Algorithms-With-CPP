#include "LinkedList.h"

// This print logic can be changed according to the item type.
template <typename T>
void print(Node<T> *itr)
{
    while (itr != NULL)
    {
        cout << *itr->value << "-->";
        itr = itr->next;
    }
    cout << "NULL" << endl;
}

int main(int argc, char **argv)
{
    LinkedList<int> l_list;
    l_list.append(new int(11));
    l_list.append(new int(12));
    l_list.prepend(new int(9));
    l_list.prepend(new int(8));
    l_list.prepend(new int(7));
    l_list.prepend(new int(6));
    l_list.prepend(new int(3));
    l_list.deleteFromStart();
    l_list.deleteFromEnd();
    l_list.append(new int(12));
    l_list.append(new int(13));
    l_list.prepend(new int(5));
    l_list.prepend(new int(4));
    l_list.prepend(new int(3));
    l_list.removeNth(0);
    cout << "Displaying LinkedList."<< endl;
    print(l_list.getNth(0));
    l_list.reverse();
    cout << "Displaying Reverse LinkedList."<< endl;
    print(l_list.getNth(0));
    cout << "Singly LinkedList Size : " << l_list.getSize() << endl;
    return 0;
}