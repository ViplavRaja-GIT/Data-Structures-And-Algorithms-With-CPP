#include "../../Data-Structures/LinkedList/LinkedList.h"
using namespace std;

template <typename T>
void DetectLoop(Node<T> *head)
{
    Node<T> *slow_ptr = head, *fast_ptr = head;
    while(slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr)
        {
            cout << "Loop Detected." << endl;
            return;
        }
    }
    cout << "No Loop Detected" << endl;
    return;
}

int main()
{
    LinkedList<int> list;
    list.append(new int(23));
    list.append(new int(44));
    list.append(new int(65));
    list.append(new int(90));
    list.append(new int(121));
    list.append(new int(435));

    Node<int> *head = list.getNth(0);
    // Creating Loop
    Node<int> *tail = list.getNth(5);
    tail->next = head;

    DetectLoop(head);
    return 0;
}