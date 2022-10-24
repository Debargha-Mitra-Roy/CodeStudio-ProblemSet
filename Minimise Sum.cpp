/*
    Minimise Sum :-

    LINK:   https://www.codingninjas.com/codestudio/problems/minimise-sum_2569272
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define mod 1000000007
#define int long long int

bool comparator(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];

    return a[0] > b[0];
}

int minimiseSum(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    int m = mat[0].size();

    // Initialse and empty array to count the sum of an element will add to cumulative sum
    vector<vector<int>> ways;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int row = ((j + 1) * (m - j)) % mod;
            int col = ((i + 1) * (n - i) - 1) % mod;

            // Count from top right and left
            int topLeft = (i * j) % mod;
            int topRight = ((m - j - 1) * i) % mod;

            // Count from bottom right and left
            int bottomLeft = (j * (n - i - 1)) % mod;
            int bottomRight = ((n - i - 1) * (m - j - 1)) % mod;

            // Count from left and right side
            int left = (j * i * (n - i - 1)) % mod;
            int right = ((m - j - 1) * i * (n - i - 1)) % mod;

            // Count from left and right side
            int top = (i * j * (m - j - 1)) % mod;
            int bottom = ((n - i - 1) * j * (m - j - 1)) % mod;

            int d1 = (topLeft * bottomRight) % mod;
            int d2 = (topRight * bottomLeft) % mod;

            // Add the total number of ways
            int total = ((row + col) % mod + (topLeft + topRight) % mod) % mod;
            total += ((bottomLeft + bottomRight) % mod + (left + right) % mod) % mod;
            total += ((top + bottom) % mod + (d1 + d2) % mod) % mod;

            // Insert total * num in the array
            ways.push_back({(total * mat[i][j]) % mod, mat[i][j]});
        }
    }

    sort(ways.begin(), ways.end(), comparator);

    int ans = 0;

    for (int i = 0; i < m * n; i++)
    {
        int element = ways[i][1];

        // If K is larger make the elementmemnt 0 and decrease K
        if (k >= element)
        {
            ways[i][1] = 0;
            k -= element;
        }

        // Otherwise decrease K from the elementmemnt
        else if (k >= 0)
        {
            ways[i][1] -= k;
            k = 0;
        }

        // If the elementment is non zero add it in the answer
        if (element != 0)
            ans = (ans + ((ways[i][0] / element) * ways[i][1]) % mod) % mod;
    }

    // Return the answer
    return ans;
}