/*
    House Robber :-

    LINK:   https://www.codingninjas.com/codestudio/problems/loot-houses_630510
*/

#include <iostream>
#include <vector>
using namespace std;

int solve(int index, vector<int> &houses, vector<int> &dp)
{
    if (index == 0)
        return houses[index];

    if (index < 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int pick = houses[index] + solve(index - 2, houses, dp);
    int nonPick = solve(index - 1, houses, dp);

    return (dp[index] = max(pick, nonPick));
}

int maxMoneyLooted(vector<int> &houses, int n)
{
    vector<int> dp(n, -1);
    return solve(n - 1, houses, dp);
}