/*
    Count Ways To Reach The N-th Stairs :-

    LINK:   https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650
*/

#include <iostream>
using namespace std;

#define mod 1000000007

int countDistinctWays(int nStairs)
{
    int prev1 = 1, prev2 = 1;

    for (int i = 2; i <= nStairs; i++)
    {
        int currElement = (prev1 + prev2) % mod;
        prev2 = prev1;
        prev1 = currElement;
    }

    return prev1;
}