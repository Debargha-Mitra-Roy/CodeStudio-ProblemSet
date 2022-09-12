/*
    LINK:   https://www.codingninjas.com/codestudio/contests/love-babbar-contest-3/problems/14474
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int rakshaBandhan(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());

    long long int sum = 0;
    int count = 0, i = n - 1;

    while (i >= 0)
    {
        /* Check if current Rakhi can be tied. */
        sum = sum + arr[i];
        if (sum <= 0)
        {
            /* No more Rakhis can be tied. */
            break;
        }

        count++;
        i--;
    }

    /* Return the final answer. */
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

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << rakshaBandhan(arr, n) << "\n";
    }

    return 0;
}

/*
    Time complexity: O(N*logN)
    Space complexity: O(1)

    Where 'N' is the size of given array.
*/