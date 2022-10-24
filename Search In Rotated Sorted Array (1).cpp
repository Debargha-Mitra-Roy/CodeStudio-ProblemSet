/*
    Search In Rotated Sorted Array :-

    LINK:
*/

#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int> &arr, int n)
{
    int left = 0, right = n - 1;

    while (left < right)
    {
        int mid = left + ((right - left) / 2);

        if (arr[mid] >= arr[0])
            left = mid + 1;

        else
            right = mid;
    }

    return left;
}

int binarySearch(vector<int> &arr, int left, int right, int k)
{
    int start = left, end = right;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (arr[mid] == k)
        {
            return mid;
            break;
        }

        else
        {
            if (arr[mid] < k)
                start = mid + 1;

            else
                end = mid - 1;
        }
    }

    return -1;
}

int findPosition(vector<int> &arr, int n, int k)
{
    int pivot = getPivot(arr, n);

    /* Binary Search on first line */
    if (k >= arr[pivot] && k <= arr[n - 1])
        return binarySearch(arr, pivot, n - 1, k);

    /* Binary Search on last line */
    else
        return binarySearch(arr, 0, pivot - 1, k);
}