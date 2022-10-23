/*
    K'th Special Number in Range :-

    LINK:   https://www.codingninjas.com/codestudio/problems/k-th-perfect-number-in-range_2569269
*/

#include <iostream>
#include <cstring>
using namespace std;

// Recursive function to find the special numbers in the range [0, X]
int kthSpecialNumberHelper(int i, int lst, int prefix, int ctr, int dp[32][4][2][2], int x)
{
    // Base condition to end the recursion call
    if (i == -1)
    {
        // If the sequence built has a 101 subarray in its binary representation
        if (ctr == 1)
            return 1;

        // Not a special number
        return 0;
    }

    // Memoization
    if (dp[i][lst][prefix][ctr] != -1)
        return dp[i][lst][prefix][ctr];

    // Variable to store the answer calculated
    int ans = 0;

    // If the prefix from 31'st bit to the i-1'th bit doesn't matches, then, obviously the number being build is smaller and we have the liberty to place both 0 and 1 at i'th position
    if (prefix == 0)
    {
        // Placing 0 at i'th position
        ans += kthSpecialNumberHelper(i - 1, (lst % 2) * 2, 0, ctr, dp, x);

        // Placing 1 at i'th position
        // If the last 2 bits placed were 1 and 0 then placing 1 gives a special number
        if (lst == 2)
            ans += kthSpecialNumberHelper(i - 1, (lst % 2) * 2 + 1, 0, 1, dp, x);

        // If the last 2 bits placed are something else then pass the old value of 'ctr'
        else
            ans += kthSpecialNumberHelper(i - 1, (lst % 2) * 2 + 1, 0, ctr, dp, x);
    }

    // If the prefix from 31'st bit to the i-1'th bit matches, then, if the i'th bit of 'X' is ON then we can place both 0 and 1
    // else if i'th bit of 'X' is OFF then we can only place 0 to generate  a number less than equal to 'X'
    if (prefix == 1)
    {
        // If the i'th bit is ON in 'X'
        if ((1 << i) & x)
        {
            // Placing 0 at i'th position
            ans += kthSpecialNumberHelper(i - 1, (lst % 2) * 2, 0, ctr, dp, x);

            // Placing 1 at i'th position, if the last 2 bits placed were 1 and 0 then placing 1 gives a special number
            if (lst == 2)
                ans += kthSpecialNumberHelper(i - 1, (lst % 2) * 2 + 1, 1, 1, dp, x);

            // If the last 2 bits placed are something else then pass the old value of 'ctr'
            else
                ans += kthSpecialNumberHelper(i - 1, (lst % 2) * 2 + 1, 1, ctr, dp, x);
        }

        // If the i'th bit is OFF in 'X'
        else
            ans += kthSpecialNumberHelper(i - 1, (lst % 2) * 2, 1, ctr, dp, x); // Placing 0 at i'th position
    }

    // Update value in correspoding entry of the 'dp' matrix to avoid future recalculations
    dp[i][lst][prefix][ctr] = ans;

    // Return the calculated value
    return dp[i][lst][prefix][ctr];
}

int kthSpecialNumber(int l, int r, int k)
{
    // Declare 'dp' matrix and set all the values equal to -1 dp[i][last][prefix][ctr] stores the count of special numbers for the binary sequence from 0'th bit to the i'th bit
    int dp[32][4][2][2];
    memset(dp, -1, sizeof(dp));

    // Calculate the count of special numbers for [0,L-1]
    int cnt = kthSpecialNumberHelper(31, 0, 1, 0, dp, l - 1);

    // Increment the value of 'cnt' by 'K'
    cnt += k;

    // Declare the variable to store the final answer
    int ans = -1;

    // Binary search
    int low = l, high = r;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        memset(dp, -1, sizeof(dp));

        // Calculate the count of special numbers for [0,mid]
        int temp = kthSpecialNumberHelper(31, 0, 1, 0, dp, mid);

        // Search for a better answer in the left half of the current space
        if (temp >= cnt)
        {
            ans = mid;
            high = mid - 1;
        }

        // Seach for the answer in the right half of the current search space
        else
            low = mid + 1;
    }

    // Return the final answer
    return ans;
}