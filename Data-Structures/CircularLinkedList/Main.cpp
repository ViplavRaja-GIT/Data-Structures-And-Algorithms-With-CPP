#include "CircularLinkedList.cpp"

int main()
{
    CircularLinkedList<int> l_list;
    l_list.append(1);
    l_list.append(2);
    l_list.append(3);
    l_list.prepend(0);
    l_list.prepend(-1);
    l_list.prepend(-2);
    l_list.prepend(-3);
    l_list.prepend(-4);
    l_list.deleteFromStart();
    l_list.deleteAtEnd();
    cout << "Displaying LinkedList."<< endl;
    l_list.print();
    l_list.reverse();
    cout << "Displaying Reverse LinkedList."<< endl;
    l_list.print();
    cout << "Circular LinkedList Size : " << l_list.getSize() << endl;
    return 0;
}