/*
    Longest Route :-

    LINK:   https://www.codingninjas.com/codestudio/problems/longest-route_1170525
*/

#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

void helper(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &v, int i, int j, int dx, int dy, int cnt)
{
    if (i == dx and j == dy)
    {
        ans = max(ans, cnt);
        return;
    }

    if (i == n or i == -1 or j == m or j == -1 or mat[i][j] == 0 or v[i][j] == 1)
        return;

    v[i][j] = 1;

    helper(n, m, mat, v, i + 1, j, dx, dy, cnt + 1);
    helper(n, m, mat, v, i - 1, j, dx, dy, cnt + 1);
    helper(n, m, mat, v, i, j + 1, dx, dy, cnt + 1);
    helper(n, m, mat, v, i, j - 1, dx, dy, cnt + 1);

    v[i][j] = 0;
}

int longestPath(int n, int m, vector<vector<int>> &mat, int sx, int sy, int dx, int dy)
{

    if (mat[sx][sy] == 0 or mat[dx][dy] == 0)
        return -1;

    vector<vector<int>> v(n, vector<int>(m, 0));

    helper(n, m, mat, v, sx, sy, dx, dy, 0);

    return ans;
}