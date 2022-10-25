/*
    Sort An Array of 0s, 1s and 2s :-

    LINK:   https://www.codingninjas.com/codestudio/problems/sort-an-array-of-0s-1s-and-2s_892977
*/

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int *arr, int n)
{
    int i = 0;
    int nextZero = 0;
    int nextTwo = n - 1;

    while (i <= nextTwo)
    {
        if (arr[i] == 0)
        {
            swap(&arr[i], &arr[nextZero]);
            i++;
            nextZero++;
        }

        else if (arr[i] == 2)
        {
            swap(arr[i], arr[nextTwo]);
            nextTwo--;
        }

        else
            i++;
    }
}