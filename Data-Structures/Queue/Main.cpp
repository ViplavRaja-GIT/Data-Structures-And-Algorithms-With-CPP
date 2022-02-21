#include "Query.cpp"
int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << "Printing queue." << endl;
    q.printQueue();
    cout << "Queue size : " << q.getSize() << endl;
    return EXIT_SUCCESS;
}