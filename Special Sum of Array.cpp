/*
    Special Sum of Array :-

    LINK:   https://www.codingninjas.com/codestudio/problems/special-sum-of-array_893340
*/

#include <iostream>
#include <vector>
using namespace std;

int specialSum(vector<int> &arr, int n)
{
    // Declare a variable 'sum' and initialize it with zero.
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        // Add each element to the variable 'sum'.
        sum += arr[i];

        if (sum > 9)
        {
            // Store the sum of the digits of the variable 'sum' in a new variable 'tempSum'.
            int tempSum = 0;
            tempSum += sum % 10;
            sum /= 10;
            tempSum += sum;

            // Update 'sum' as 'tempSum'.
            sum = tempSum;
        }
    }

    return sum;
}