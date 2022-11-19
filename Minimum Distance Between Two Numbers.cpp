/*
    Minimum Distance Between Two Numbers :-

    LINK:   https://www.codingninjas.com/codestudio/problems/minimum-distance-between-two-numbers_1062637
*/

#include <iostream>
using namespace std;

int minimunDistance(int arr[], int n, int x, int y)
{
    int countX = 0, countY = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            countX++;

        if (arr[i] == y)
            countY++;
    }

    if (countX >= 1 && countY >= 1)
        return abs(x - y);

    else
        return -1;
}