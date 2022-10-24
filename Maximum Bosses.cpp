/*
    Maximum Bosses :-

    LINK:   https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-9/problems/17040
*/

#include <iostream>
#include <vector>
using namespace std;

int maximumBosses(int n, int p, vector<int> power)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (p > power[i] && p != 0)
            count++;

        else
            break;

        p = p - power[i];
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

        int p;
        cin >> p;

        cout << maximumBosses(n, p, v) << "\n";
    }

    return 0;
}