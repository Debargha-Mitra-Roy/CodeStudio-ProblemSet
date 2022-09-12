/*
    LINK:   https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-9/problems/16812
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumDistancePairs(int n, vector<int> &arr) {

    sort(arr.begin(), arr.end());

    int mini = arr[n - 1] - arr[0];

    for (int i = 0; i < n - 1; i++)
    {
        mini = min(mini, (arr[i + 1] - arr[i]));
    }

    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] == mini)
            count++;

        else
            continue;
    }

    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }


        cout << minimumDistancePairs(n, v) << "\n";
    }

    return 0;
}