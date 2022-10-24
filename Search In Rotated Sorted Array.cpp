/*
    Search In Rotated Sorted Array :-

    LINK:
*/

#include <iostream>
#include <vector>
using namespace std;

int getPivot(int *arr, int n)
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

int binarySearch(int *arr, int left, int right, int k)
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

int search(int *arr, int n, int key)
{
    int pivot = getPivot(arr, n);

    /* Binary Search on first line */
    if (key >= arr[pivot] && key <= arr[n - 1])
        return binarySearch(arr, pivot, n - 1, key);

    /* Binary Search on last line */
    else
        return binarySearch(arr, 0, pivot - 1, key);
}