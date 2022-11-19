/*
    N-th Fibonacci Number :-

    LINK:   https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_1115780
*/

#include <iostream>
#include <vector>
using namespace std;

#define mod 1000000007

int dp[1000000];

int fibonacciNumber(int n)
{
    if (n <= 1)
        return n;

    int x, y;

    if (dp[n - 1] != 0)
        x = dp[n - 1] % mod;

    else
        x = fibonacciNumber(n - 1);

    if (dp[n - 2] != 0)
        y = dp[n - 2] % mod;

    else
        y = fibonacciNumber(n - 2);

    return (dp[n] = (x + y) % mod);
}