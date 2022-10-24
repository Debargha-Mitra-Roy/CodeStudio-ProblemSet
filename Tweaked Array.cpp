/*
    Tweaked Array :-

    LINK:
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> tweakTheArray(vector<int> arr, int n)
{
    // Store the sum of all the elements in 'totalSum'.
    int totalSum = 0;

    // Calculating totalSum
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }

    // Store tweaked array in 'tweakedArr'.
    vector<int> tweakedArr(n);

    // Calculating the Tweaked array
    for (int i = 0; i < n; i++)
    {
        tweakedArr[i] = totalSum - arr[i];
    }

    // Return the Tweaked array
    return tweakedArr;
}
