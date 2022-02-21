#include "LinkedList"
int main(int argc, char **argv)
{
    LinkedList<int> l_list;
    l_list.append(10);
    l_list.append(11);
    l_list.append(12);
    l_list.prepend(9);
    l_list.prepend(8);
    l_list.prepend(7);
    l_list.prepend(6);
    l_list.prepend(3);
    l_list.deleteFromStart();
    l_list.deleteFromEnd();
    l_list.append(12);
    l_list.append(13);
    l_list.prepend(5);
    l_list.prepend(4);
    cout << "Displaying LinkedList."<< endl;
    l_list.print();
    l_list.reverse();
    cout << "Displaying Reverse LinkedList."<< endl;
    l_list.print();
    cout << "Singly LinkedList Size : " << l_list.getSize() << endl;
    return 0;
}