/*
    Maximise Dot Product :-

    LINK:   https://www.codingninjas.com/codestudio/problems/maximise-dot-product_1473847
*/

#include <iostream>
#include <vector>
using namespace std;

int maxDotProduct(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size(), m = arr2.size();

    // Initializing 'dp' with 0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        // 'j' starts with i, because the remaining j-1 elements of arr2 need at least j-1 elements from arr1 to be paired.
        for (int j = i; j <= n; j++)
        {
            // dp[i][j] is equal to the max of:
            // Pair arr1[j-1] with arr2[i-1] + answer till index i-1, j-1
            // Do not pair arr2[i-1] with arr1[j-1], instead pair it with some previous index of arr1.
            dp[i][j] = max(dp[i - 1][j - 1] + arr1[j - 1] * arr2[i - 1], dp[i][j - 1]);
        }
    }

    // Return the value till index m, n
    return dp[m][n];
}