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
class Stack
{
private:
    int size_;
    Node<T> *top = NULL;

public:
    Stack() : size_(0){};

    void push(T value)
    {
        Node<T> *ele = new Node<T>(value);
        if (top == NULL)
        {
            this->top = ele;
        }
        else
        {
            ele->next = this->top;
            this->top = ele;
        }
        this->size_ += 1;
    }

    T pop()
    {
        if(top == NULL)
        {
            throw runtime_error("Stack is empty.");
        }
        else 
        {
            Node<T> *ele = this->top;
            this->top = this->top->next;
            this->size_ -= 1;
            return ele->value;
        }
    }

    T peek()
    {
        return this->top->value;
    }

    int getSize()
    {
        return this->size_;
    }

    void printStack()
    {
        if (top == NULL)
        {
            throw runtime_error("Stack is empty.");
        }
        else
        {
            Node<T> *itr = top;
            while (itr->next != NULL)
            {
                cout << "[" << itr->value << "]--";
                itr = itr->next;
            }
            cout << "[" << itr->value << "]" << endl;
        }
    }
};