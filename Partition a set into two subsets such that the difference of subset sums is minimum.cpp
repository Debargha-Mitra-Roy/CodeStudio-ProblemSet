/*
    Partition a set into two subsets such that the difference of subset sums is minimum :-

    LINK:   https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
*/

#include <iostream>
#include <vector>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n)
{
    if (n == 1)
        return arr[0];

    int sum = 0;

    for (int &x : arr)
        sum += x;

    // To minimize the diff, both subsets must be closely equal, here ~ sum/2
    int knapsackSum = sum / 2;

    // Here we feel, we are allowed to have sum not more than a limit (same as in knapsack 0/1)
    vector<vector<int>> dp(n + 1, vector<int>(knapsackSum + 1));

    // For no item no subset is possible to contribute a weight, but 0 wt possible
    for (int i = 0; i <= knapsackSum; ++i)
    {
        dp[0][i] = 0;
    }

    // For 0 wt, always a possible soln
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = 1;
    }

    int ansSum = 0;

    // Will perform knapsack 0/1 as to proceed on two possibility 1. consider an element and 2. not consider.
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= knapsackSum; ++j)
        {
            // If we have capacity to include cur ele, then we will take both cases include or not include , else if bag not sufficient then directly exclude. hence 3 cases. {i-1,j} means excluding cur element and {i-1, j-arr[i-1]} means considering cur element.
            dp[i][j] = j >= arr[i - 1] ? dp[i - 1][j] | dp[i - 1][j - arr[i - 1]] : dp[i - 1][j];

            // Here max possible sum is being remembered saving extra iteration
            if (i == n && dp[i][j])
                ansSum = j;
        }
    }

    return abs(ansSum - (sum - ansSum));
}