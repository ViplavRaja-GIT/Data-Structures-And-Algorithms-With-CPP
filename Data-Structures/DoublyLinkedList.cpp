#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
class Node
{
public:
    T value;
    Node *next = NULL;
    Node *prev = NULL;
    Node(T value)
    {
        this->value = value;
    }
};

template <typename T>
class LinkedList
{
private:
    int size_;
    Node<T> *head = NULL;

public:
    LinkedList():size_(0){}

    void append(T value)
    {
        if (this->head == NULL)
        {
            this->head = new Node<T>(value);
        }
        else
        {
            Node<T> *itr = head;
            while (itr->next != NULL)
            {
                itr = itr->next;
            }
            itr->next = new Node<T>(value);
            itr->next->prev = itr;
        }
        this->size_ += 1;
    }

    void prepend(T value)
    {
        Node<T> *itr = head;
        head = new Node<T>(value);
        head->next = itr;
        itr->prev = head;
        this->size_ += 1;
    }

    void deleteFromStart()
    {
        if (head == NULL)
        {
            throw runtime_error("List is empty.");
        }
        Node<int> *itr = head;
        head = head->next;
        head->prev = NULL;
        delete itr;
        this->size_ -= 1;
    }

    void deleteFromEnd()
    {
        if (head == NULL)
        {
            throw runtime_error("List is empty.");
        }
        Node<int> *itr = head;
        while (itr->next->next != NULL)
        {
            itr = itr->next;
        }
        delete(itr->next);
        itr->next = NULL;
        this->size_ -= 1;
    }

    void reverse()
    {
        Node<T> *current = head, *temp = NULL;
        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if(temp != NULL)
            head = temp->prev;
        head->prev = NULL;
    }

    void print()
    {
        cout << "NULL<--";
        Node<T> *itr = head;
        while (itr->next != NULL)
        {
            cout << itr->value << "<-->";
            itr = itr->next;
        }
        cout << itr->value << "-->NULL" << endl;
    }

    void reversePrint()
    {
        Node<T> *itr = head;
        while (itr->next != NULL)
        {
            itr = itr->next;
        }
        cout << "NULL<--";
        while (itr->prev != NULL)
        {
            cout << itr->value << "<-->";
            itr = itr->prev;
        }
        cout << itr->value << "-->NULL" << endl;
    }

    int getSize()
    {
        return this->size_;
    }
};

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