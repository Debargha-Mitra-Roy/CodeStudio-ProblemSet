/*
    Bits Counting :-

    LINK:   https://www.codingninjas.com/codestudio/problems/bits-counting_3164680
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> count(int n)
{
    vector<int> ans(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        ans[i] = ans[i >> 1] + (i & 1);
    }

    return ans;
}