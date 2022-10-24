/*
    PAINT THE FENCE :-

    LINK:   https://www.codingninjas.com/codestudio/problems/paint-the-fence_873850
*/

#include <iostream>
#include <vector>
using namespace std;

int paintTheFence(vector<vector<int>> &ranges, int n, int q)
{
    vector<int> wall(n + 1, 0);

    for (int i = 0; i < q; i++)
    {
        for (int j = ranges[i][0]; j <= ranges[i][1]; j++)
        {
            wall[j] += i + 1;
        }
    }

    int count = 0;
    int flag = true;

    for (int i = 1; i < n + 1; i++)
    {
        // Check that, Is there any wall or fence section painted by more then 2 painter's
        if (wall[i] > q)
            flag = false;

        // Fence section is painted or not
        if (wall[i] > 0)
            count++;
    }

    if (flag)
        return (q - 2);

    return count;
}