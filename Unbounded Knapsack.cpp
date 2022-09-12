/*
    Unbounded Knapsack :-

    LINK:   https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        // dp[i] is going to store maximum profit with knapsack capacity i.
        int dp[w + 1];
        memset(dp, 0, sizeof dp);

        // Fill dp[] using above recursive formula
        for (int i = 0; i <= w; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (weight[j] <= i)
                    dp[i] = max(dp[i], (dp[i - weight[j]] + profit[j]));
            }
        }

        return dp[w];
    }
};