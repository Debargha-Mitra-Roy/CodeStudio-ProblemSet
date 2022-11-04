/*
    Alternate Positive and Negative :-

    LINK:   https://www.codingninjas.com/codestudio/problems/alternatives_893342
*/

#include <iostream>
#include <vector>
using namespace std;

void posAndNeg(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, 0);

    for (int i = 0, j = 1, k = 0; k < n; k++)
    {
        if (arr[k] >= 0)
        {
            ans[i] = arr[k];
            i += 2;
        }

        else
        {
            ans[j] = arr[k];
            j += 2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
}