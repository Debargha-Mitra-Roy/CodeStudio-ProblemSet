/*
    Allocate Books :-

    LINK:   https://www.codingninjas.com/codestudio/problems/allocate-books_1090540
*/

#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
            pageSum = pageSum + arr[i];

        else
        {
            studentCount++;

            if (studentCount > m || arr[i] > mid)
                return false;

            pageSum = arr[i];
        }
    }

    return true;
}

int allocateBooks(vector<int> &arr, int n, int m)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    int start = 0, end = sum;

    int ans = 0;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }

        else
            start = mid + 1;
    }

    return ans;
}