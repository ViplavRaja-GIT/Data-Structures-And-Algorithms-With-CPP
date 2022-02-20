#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
class Node
{
public:
    T value;
    Node *next = NULL;
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
        }
        this->size_ += 1;
    }

    void prepend(T value)
    {
        Node<T> *itr = head;
        head = new Node<T>(value);
        head->next = itr;
        this->size_ += 1;
    }

    void deleteFromStart()
    {
        if(head == NULL)
        {
            throw runtime_error("List empty.");
        }
        else if(head == head->next)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node<int> *itr = head;
            head = head->next;
            delete itr;
            this->size_ -= 1;
        }
    }

    void deleteFromEnd()
    {
        if (head == NULL)
        {
            throw runtime_error("List is empty.");
        }
        else if(head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else 
        {
            Node<int> *itr = head;
            while (itr->next->next != NULL)
            {
                itr = itr->next;
            }
            delete(itr->next);
            itr->next = NULL;
        }
        this->size_ -= 1;
    }

    void reverse()
    {
        if (head == NULL)
        {
            throw runtime_error("List is empty.");
        }
        Node<T> *current = head, *next = NULL, *prev = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next; 
        }
        head = prev;
    }

    void print()
    {
        Node<T> *itr = head;
        while (itr != NULL)
        {
            cout << itr->value << "-->";
            itr = itr->next;
        }
        cout << "NULL" << endl;
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