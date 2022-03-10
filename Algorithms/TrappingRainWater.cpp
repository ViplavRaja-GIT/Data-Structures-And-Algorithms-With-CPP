#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int trappedWater(int bars[], int n)
{
    // base case
    if(n <= 2) {
        return 0;
    }

    int water = 0;

    // `left[i]` stored the maximum height of a bar to the left
    // of the current bar
    int *left = new int[n-1];
    left[0] = INT_MIN;


    // process bars from left to right
    for (int i = 1; i < n-1; i++)
    {
        left[i] = max(left[i-1], bars[i-1]);
    }

    // `right` stored the maximum height of a bar to the right
    // of the current bar
    int right = INT_MIN;

    // process bars from roght to left
    for(int i = n-2; i>=1; i--)
    {
        right = max(right, bars[i+1]);
        if(min(left[i], right) > bars[i])
        {
            water += min(left[i], right) - bars[i];
        }
    }
    return water;
}

int main()
{
    int heights[] = { 7, 0, 4, 2, 5, 0, 6, 4, 0, 0 };
    int n = sizeof(heights) / sizeof(heights[0]);
 
    printf("The maximum amount of water that can be trapped is %d.",
            trappedWater(heights, n));
    return 0;
}