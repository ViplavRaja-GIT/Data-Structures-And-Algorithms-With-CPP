#include<iostream>
#include<vector>
#include "Fibonacci.cpp"
#include "FibonacciNth.cpp"
using namespace std;

int main()
{
    int sequenceIndex = 9;
    vector<int> result = Fibonacci(sequenceIndex);
    cout<< "Print fibonacci sequence till " << sequenceIndex << "th index." << endl;
    for (auto i = result.begin(); i != result.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << "\n\nPrint fibonacci number of " << sequenceIndex << "th index.\n" << FibonacciNth(9) << endl;
    return 0;
}