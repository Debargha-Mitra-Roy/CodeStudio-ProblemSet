/*
    Frog Jump :-

    LINK:   https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minEnergy(int n, vector<int> &heights, vector<int> &dp)
{
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int first = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int second = INT_MAX;

        if (i > 1)
            second = dp[i - 2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(first, second);
    }

    return dp[n];
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);

    return minEnergy(n - 1, heights, dp);
}