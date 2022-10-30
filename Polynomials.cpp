/*
    Polynomials :-

    LINK:   https://www.codingninjas.com/codestudio/problems/polynomials_3164694
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(vector<int> &a, vector<int> &b, int n)
{

    vector<int> ans(2 * n - 1);

    // Polynomial Multiplication
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i + j] += a[i] * b[j];
        }
    }

    return ans;
}