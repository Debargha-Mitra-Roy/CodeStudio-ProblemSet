/*
    Find Duplicate :-

    LINK:   https://www.codingninjas.com/codestudio/problems/find-duplicate_625160
*/

#include <iostream>
#include <algorithm>
using namespace std;

int findDuplicate(int *arr, int size)
{
    sort(arr, arr + size);

    int ans = 0;

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            ans = arr[i];
    }

    return ans;
}