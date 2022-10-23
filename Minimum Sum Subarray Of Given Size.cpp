/*
    Minimum Sum Subarray Of Given Size :-

    LINK:   https://www.codingninjas.com/codestudio/problems/find-minimum-sum-subarray-of-given-size_873368
*/

#include <iostream>
#include <climits>
using namespace std;

int minSubarraySum(int arr[], int n, int k)
{
    int maxSum = INT_MAX, kSum = 0;

    for (int i = 0; i < k; i++)
    {
        kSum += arr[i];
    }

    maxSum = min(maxSum, kSum);
    int temp = k;

    while (k < n)
    {
        kSum = kSum + arr[k] - arr[k - temp];
        maxSum = min(maxSum, kSum);
        k++;
    }

    return maxSum;
}