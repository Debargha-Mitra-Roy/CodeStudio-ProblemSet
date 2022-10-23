/*
    Ninja’s Test :-

    LINK:   https://www.codingninjas.com/codestudio/problems/ninja-s-test_2674276
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void findLeftSmaller(int n, vector<int> &arr, int *leftSmaller)
{
    // Initialize an empty stack 'ST'.
    stack<int> st;

    // Iterate 'I' in 0 to 'N'
    for (int i = 0; i < n; i++)
    {
        // Keep removing the top of the 'ST' while it is greater than or equal to 'ARR[I]'.
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        // If 'ST' is not empty, then the top is the left samller element of the current element.
        if (!st.empty())
            leftSmaller[i] = st.top();

        // Otherwise, there is no left smaller element of the current element.
        else
            leftSmaller[i] = 0;

        // Push current element to 'ST'.
        st.push(arr[i]);
    }
}

int maxDifference(int n, vector<int> &arr)
{
    // Initialize an integer array 'LEFTSMALLER' of size 'N'
    int leftSmaller[n];

    // Call 'FINDLEFTSMALLER' to find left smaller element of every element.
    findLeftSmaller(n, arr, leftSmaller);

    // Initialize an integer array 'RIGHTSMALLER' of size 'N'
    int rightSmaller[n];

    // Reverse the 'ARR' to use 'FINDLEFTSMALLER' to find right smaller element of every element.
    reverse(arr.begin(), arr.end());

    // Call 'findLeftSmaller' to find left smaller element of every element.
    findLeftSmaller(n, arr, rightSmaller);

    // Initialize a variable 'ANS' to store final answer.
    int ans = 0;

    // Iterate 'I' in 0 to 'N'
    for (int i = 0; i < n; i++)
    {
        // Set 'ANS' to the maximum of 'ANS' and 'ABSOLUTE'('LEFTSMALLER[I]' - 'RIGHTSMALLER[I]')
        ans = max(ans, abs(leftSmaller[i] - rightSmaller[i]));
    }

    // Finally, return 'ANS'.
    return ans;
}