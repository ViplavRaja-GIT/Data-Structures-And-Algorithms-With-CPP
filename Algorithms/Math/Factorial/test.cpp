#include<iostream>
#include "Factorial.cpp"
#include "FactorialRecursive.cpp"
using namespace std;

int main()
{
    int fact = 23;
    cout << "Calculating factorial of number " << fact << "." << endl;
    cout << Factorial(fact) << endl;
    cout << "Calculating factorial of number " << fact << " recursively." << endl;
    cout << FactorialRecursive(fact) << endl;
}