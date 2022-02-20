#include <iostream>
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
    LinkedList() : size_(0) {}
    
    int getSize()
    {
        return this->size_;
    }

    void append(T value)
    {
        Node<T> *ele = new Node<T>(value);
        if (head == NULL)
        {
            head = ele;
        }
        else
        {
            Node<T> *itr = head;
            while (itr->next != head)
            {
                itr = itr->next;
            }
            itr->next = ele;
        }
        ele->next = head;
        this->size_ += 1;
    }

    void prepend(T value)
    {
        Node<T> *ele = new Node<T>(value);
        if (head == NULL)
        {
            head = ele;
        }
        else
        {
            Node<T> *itr = head;
            while (itr->next != head)
            {
                itr = itr->next;
            }
            itr->next = ele;
        }
        ele->next = head;
        head = ele;
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
            Node<T> *end = head;
            while (end->next != head)
            {
                end = end->next;
            }
            end->next = head->next;
            Node<T> *toDelete = head;
            head = head->next;
            delete toDelete;
        }
        this->size_ -= 1;
    }

    void deleteAtEnd()
    {
        if(head == NULL)
        {
            throw runtime_error("List Empty");
        }
        else if(head == head->next)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node<T> *temp = head;
            while(temp -> next -> next != head)
            {
                temp = temp->next;
            }
            Node<T> *itr = temp->next;
            temp->next = itr->next;
            delete itr;
        }
        this->size_ -= 1;
    }

    void reverse()
    {
        Node<T> *current = head->next, *next = head->next, *prev = head;
        while (next != head)
        {
            next = next->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        current->next = prev;
        head = prev;
    }

    void print()
    {
        if(head == NULL)
            throw runtime_error("List is empty.");
        Node<T> *itr = head;
        while (itr->next != head)
        {
            cout << "(" << itr->value << ")-->";
            itr = itr->next;
        }
        cout << "(" << itr->value << ")-->NULL"<< endl;
    }
};

int main()
{
    LinkedList<int> l_list;
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