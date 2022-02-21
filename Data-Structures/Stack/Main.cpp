#include "Stack.cpp"
int main()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(12);
    stack.push(10);
    stack.push(14);
    stack.push(16);
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    cout << "Printing Stack." << endl;
    stack.printStack();
    cout << "Stack size : " << stack.getSize() << endl;
    return 0;
}