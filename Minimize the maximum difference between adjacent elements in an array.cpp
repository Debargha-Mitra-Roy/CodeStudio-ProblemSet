/*
    Minimize the maximum difference between adjacent elements in an array :-

    LINK:   https://www.codingninjas.com/codestudio/problems/minimize-the-maximum-difference-between-adjacent-elements-in-an-array_893177
*/

#include <iostream>
#include <vector>
using namespace std;

int maxAdjDifference(vector<int> &arr, int k)
{
    int start = 0;
    int end = arr.size() - 1;

    if (k > (end - start))
        return 0;

    while (k != 0)
    {
        if (k % 2 == 0)
        {
            start = start + 1;
            end = end - 1;
            k = k - 2;
        }

        else
        {
            int a = arr[start + 1] - arr[start];
            int b = arr[end] - arr[end];

            if (a > b)
                start = start + 1;

            else if (b >= a)
                end = end - 1;

            k = k - 1;
        }
    }

    int max_difference = 0;

    for (int i = start + 1; i <= end; i++)
    {
        int curr_difference = arr[i] - arr[i - 1];
        max_difference = max(max_difference, curr_difference);
    }

    return max_difference;
}