#include <iostream>
using namespace std;

template <typename T>
class Node{
    public:
        T value;
        Node *next = NULL;
        Node(T value)
        {
            this->value = value;
        }
};

template <typename T>
class Queue
{
    private:
        int size_;
        Node<T> *head = NULL;
    public:
        Queue()
        {
            this->size_ = 0;
        }

        int getSize()
        {
            return this->size_;
        }

        void enqueue(T value)
        {
            Node<T> *ele = new Node<T>(value);
            if(this->head == NULL)
            {
                this->head = ele;
            }
            else
            {
                Node<T> *itr = head;
                while (itr->next != NULL)
                {
                    itr = itr->next;
                }
                itr->next = ele;
            }
            this->size_ += 1;
        }

        T dequeue()
        {
            if(head == NULL)
            {
                throw runtime_error("Queue is empty.");
            }
            else
            {
                Node<T> *itr = head;
                while(itr->next->next != NULL)
                {
                    itr = itr->next;
                }
                Node<T> *toDelete = itr->next;
                T value = toDelete->value;
                delete toDelete;
                itr->next = NULL;
                this->size_ -= 1;
                return value;
            }
        }

        void printQueue()
        {
            if (this->head == NULL)
            {
                throw runtime_error("Stack is empty.");
            }
            else
            {
                Node<T> *itr = this->head;
                while (itr->next != NULL)
                {
                    cout << "(" << itr->value << ")--";
                    itr = itr->next;
                }
                cout << "(" << itr->value << ")" << endl;
            }
        }
};