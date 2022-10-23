/*
    Pascal's Triangle :-

    LINK:   https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_1089580
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> triangle;
    vector<long long int> temp;

    for (int i = 1; i <= n; i++)
    {
        long long int rCe = 1;
        temp.clear();

        for (int j = 1; j <= i; j++)
        {
            temp.push_back(rCe);
            rCe = rCe * (i - j) / j;
        }

        triangle.push_back(temp);
    }

    return triangle;
}
