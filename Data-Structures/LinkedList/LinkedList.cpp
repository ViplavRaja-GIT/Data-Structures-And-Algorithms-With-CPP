#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList():size_(0){}

template <typename T>
void LinkedList<T>::append(T *value)
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

template <typename T>
void LinkedList<T>::prepend(T *value)
{
    Node<T> *itr = head;
    head = new Node<T>(value);
    head->next = itr;
    this->size_ += 1;
}

template <typename T>
void LinkedList<T>::deleteFromStart()
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

template <typename T>
void LinkedList<T>::deleteFromEnd()
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

template <typename T>
void LinkedList<T>::reverse()
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

template <typename T>
int LinkedList<T>::getSize()
{
    return this->size_;
}

template <typename T>
Node<T>*  LinkedList<T>::getNth(int index)
{
    if(index > size_-1)
    {
        throw runtime_error("List is empty.");
    }
    Node<T> *temp = head;
    while(index-- != 0)
    {
        temp = temp->next;
    }
    return temp;
}

template <typename T>
void LinkedList<T>::removeNth(int index)
{
    if(index > size_-1)
    {
        throw runtime_error("List is empty.");
    }
    Node<T> *temp = head;
    if(index == 0)
    {
        head = head->next;
        delete temp;
    } 
    else
    {
        while(index != 1)
        {
            temp = temp->next;
        }
        Node<T> *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    this->size_-=1;
}