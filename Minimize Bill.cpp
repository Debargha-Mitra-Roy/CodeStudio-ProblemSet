/*
    Minimize Bill :-

    LINK:   
*/

#include<iostream>
#include<vector>
using namespace std;

long long int totalBill(int n, vector<int> &a)
{
    int maxx = a[0];
    long long int sum = 0;

    for (long long int i = 0; i < n; i++)
    {
        maxx = max(maxx, a[i]);
        sum = sum + a[i];
    }

    long long int ans = sum - (2 * maxx);

    return ans;
}