#include<vector>
using namespace std;

int FibonacciNth(int n)
{
    vector<int> vec;
    int crrValue = 1;
    int preValue = 0;
    if(n == 1)
    {
        return 1;
    }
    int iterationCount = n-1;
    while(iterationCount)
    {
        crrValue += preValue;
        preValue = crrValue - preValue;
        iterationCount--;
    }
    return crrValue;
}