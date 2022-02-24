#include <iostream>
using namespace std;

#ifndef LINKEDLIST
#define LINKEDLIST

template <typename T>
class Node
{
public:
    T *value;
    Node *next = NULL;
    Node(T *value)
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
        LinkedList();
        void append(T *value);
        void prepend(T *value);
        void deleteFromStart();
        void deleteFromEnd();
        void reverse();
        int getSize();
        Node<T>* getNth(int index);
        void removeNth(int index);
};

#include "LinkedList.cpp"
#endif