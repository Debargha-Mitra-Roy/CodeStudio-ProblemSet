/*
    Add One To Number :-

    LINK:   https://www.codingninjas.com/codestudio/problems/add-one-to-number_873367
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> addOneToNumber(vector<int> arr)
{
    // Reverse the given array
    reverse(arr.begin(), arr.end());

    // Remove leading zeros
    while (arr.size() > 1 && arr.back() == 0)
    {
        arr.pop_back();
    }

    int n = arr.size();
    int carry = 1;

    // Iterate for all digits.
    for (int i = 0; i < n; i++)
    {
        // Store sum in 'd'
        int d = arr[i] + carry;

        // Update current digit and carry.
        arr[i] = d % 10;
        carry = d / 10;
    }

    if (carry != 0)
        arr.push_back(carry);

    // Reverse the array
    reverse(arr.begin(), arr.end());

    return arr;
}