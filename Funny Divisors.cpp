/*
    Funny Divisors :-

    LINK:   https://www.codingninjas.com/codestudio/problems/multiples-of-2-and-3_893308
*/

#include <iostream>
#include <vector>
using namespace std;

int findSum(int n, vector<int> &arr)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0 || arr[i] % 3 == 0)
            sum += arr[i];
    }

    return sum;
}