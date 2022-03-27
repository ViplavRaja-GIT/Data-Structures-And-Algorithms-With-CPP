#include<vector>
using namespace std;

vector<int> Fibonacci(int n)
{
    vector<int> vec;
    vec.push_back(1);
    int crrValue = 1;
    int preValue = 0;
    if(n==1)
    {
        return vec;
    }
    int iterationCount = n-1;
    while (iterationCount)
    {
       crrValue += preValue;
       preValue = crrValue - preValue;
       vec.push_back(crrValue);
       iterationCount--;
    }
    return vec;
}