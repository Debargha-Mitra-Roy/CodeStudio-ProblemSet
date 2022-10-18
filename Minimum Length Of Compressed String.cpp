/*
    Minimum Length Of Compressed String :-

    LINK:   https://www.codingninjas.com/codestudio/problems/minimum-length-of-compressed-string_893033
*/

#include <iostream>
#include <vector>
using namespace std;

int helper(string &str, int n, int curIdx, int k, int prevChar, int cntPrevChar, vector<vector<vector<vector<int>>>> &dp)
{
    /*
        Parameter of this function are -:
        str: Given string.
        n: Length of given string.
        curIdx: current index in str.
        k: Remaining number of deletion.
        prevChar: previous character.
        cntPrevChar: Number of occurrences of the previous character.
    */

    // If the entire string has been traversed
    if (curIdx == n)
        return 0;

    // If subproblem is already computed.
    if (dp[curIdx][k][prevChar][cntPrevChar] != -1)
        return dp[curIdx][k][prevChar][cntPrevChar];

    int result = n + 1;

    // Minimum run length encoding by removing the currrent character.
    if (k > 0)
        result = helper(str, n, curIdx + 1, k - 1, prevChar, cntPrevChar, dp);

    // Minimum run length encoding by retaining the currrent character.
    if (str[curIdx] - 'a' == prevChar)
    {
        // If the current and the previous characters are same.
        int increment = 0;

        if (cntPrevChar == 1 || cntPrevChar == 9 || cntPrevChar == 99)
            increment = 1;

        result = min(result, helper(str, n, curIdx + 1, k, prevChar, cntPrevChar + 1, dp) + increment);
    }

    else
        // If the current and the previous characters are not same.
        result = min(result, helper(str, n, curIdx + 1, k, str[curIdx] - 'a', 1, dp) + 1);

    // Store result in 'dp' table
    dp[curIdx][k][prevChar][cntPrevChar] = result;

    return dp[curIdx][k][prevChar][cntPrevChar];
}

int minLengthOfCompressedString(string &str, int k)
{
    // Length of given string.
    int n = str.length();

    // Initialize and fill 'dp' table by -1.
    vector<vector<vector<vector<int>>>> dp = vector<vector<vector<vector<int>>>>(n, vector<vector<vector<int>>>(k + 1, vector<vector<int>>(27, vector<int>(n + 1, -1))));

    // Recursively calculate minimum length of compressed string.
    return helper(str, n, 0, k, 26, 0, dp);
}