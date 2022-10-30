/*
    Longest Mountain Subarray :-

    LINK:   https://www.codingninjas.com/codestudio/problems/longest-mountain-subarray_893069
*/

#include <iostream>
using namespace std;

int longestMountain(int *arr, int n)
{
    if (n < 3)
        return 0;

    int start = -1, end = -1;
    int ans = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i + 1] > arr[i])
        {
            if (end != -1)
            {
                end = -1;
                start = -1;
            }

            if (start == -1)
                start = i;
        }

        else
        {
            if (arr[i + 1] < arr[i])
            {
                if (start != -1)
                    end = i + 1;

                if (end != -1 && start != -1)
                    ans = max(ans, end - start + 1);
            }

            else
            {
                start = -1;
                end = -1;
            }
        }
    }

    if (end != -1 && start != -1)
        ans = max(ans, end - start + 1);

    return ans;
}