/*
    Bursting Balloons :-

    LINK:   https://www.codingninjas.com/codestudio/problems/bursting-balloons_701653
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int burstingBalloons(int *arr, int n)
{
    unordered_map<int, int> arrowsAtHeight;

    for (int i = 0; i < n; i++)
    {
        if (arrowsAtHeight.find(arr[i]) != arrowsAtHeight.end())
        {
            // Destroying Ballon So Frequency will decrease.
            arrowsAtHeight[arr[i]]--;

            if (arrowsAtHeight[arr[i]] == 0)
            {
                arrowsAtHeight.erase(arr[i]);
            }
        }

        // Frequency of Arrow at 1 less height will increase.
        arrowsAtHeight[arr[i] - 1]++;
    }

    int ans = 0;

    for (auto arrow : arrowsAtHeight)
    {
        ans += arrow.second;
    }

    return ans;
}