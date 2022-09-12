/*
    Bubble Sort :-

    LINK:   https://www.codingninjas.com/codestudio/problems/bubble-sort_980524
*/

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    /* For round 1 to (n - 1) */
    for (int i = 1; i < n; i++)
    {
        bool isSwapped = false;

        /* Process element till (n - i)th index */
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isSwapped = true;
            }
        }

        if (isSwapped == false) // Optimise the code for best case time complexity ie. if the Array is already sorted
            break;
    }
}