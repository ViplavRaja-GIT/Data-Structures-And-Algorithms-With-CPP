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