/*
    Gold mine problem :-

    LINK:   https://www.codingninjas.com/codestudio/problems/gold-mine-problem_799363
*/

#include <iostream>
#include <vector>
using namespace std;

int collect(vector<vector<int>> &mine, int r, int c, int n, int m, vector<vector<int>> &dp)
{
    // Base condition.
    if ((r < 0) || (r == n) || (c == m))
        return 0;

    // If best answer already known,
    if (dp[r][c] != -1)
        return dp[r][c];

    // Right upper diagonal.
    int upperDiagonal = collect(mine, r - 1, c + 1, n, m, dp);

    // Straight right.
    int straight = collect(mine, r, c + 1, n, m, dp);

    // Lower right diagonal.
    int lowerDiagonal = collect(mine, r + 1, c + 1, n, m, dp);

    // Store the best answer in dp matrix and return.
    return dp[r][c] = mine[r][c] + max(max(upperDiagonal, straight), lowerDiagonal);
}

int maxGoldCollected(vector<vector<int>> mine, int n, int m)
{
    int maxGold = 0;

    // Initialize the dp matrix.
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        // Recursive function call for  ith row.
        int goldCollected = collect(mine, i, 0, n, m, dp);
        maxGold = max(maxGold, goldCollected);
    }

    return maxGold;
}