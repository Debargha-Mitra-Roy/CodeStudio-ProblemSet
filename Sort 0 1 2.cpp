/*
    Sort 0 1 2 :-

    LINK:   https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055
*/

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort012(int *arr, int n)
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