/*
    Diagonals :-

    LINK:   
*/

#include <iostream>
#include <vector>
using namespace std;

int diagonals(vector<vector<int>> &num)
{
    vector<int> s1, s2;

    int left = 0, right = 0;
    int n = num.size();

    for (int i = 0; i < n; i++)
    {
        left = num[i][i];
        s1.push_back(left);

        right = num[i][n - i - 1];
        s2.push_back(right);
    }

    int sum1 = 0, sum2 = 0, diff = 0;
    int mid = n / 2;

    for (int i = 0; i < s1.size(); i++)
    {
        if (n % 2 != 0)
        {
            if (s1[mid] == s2[mid])
                diff = s1[mid];
        }

        sum1 = sum1 + s1[i];
        sum2 = sum2 + s2[i];
    }

    int ans = (sum1 + sum2) - diff;

    return ans;
}