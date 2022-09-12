/*
    Insertion Sort :-

    LINK:   https://www.codingninjas.com/codestudio/problems/insertion-sort_3155179
*/

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int n, vector<int> &arr)
{
    int i = 0;

    while (i < n)
    {
        int temp = arr[i];

        int j = i - 1;

        while (j >= 0)
        {
            if (arr[j] > temp)
                arr[j + 1] = arr[j]; // Shift

            else
                break; // Stop

            j--;
        }

        arr[j + 1] = temp;

        i++;
    }
}