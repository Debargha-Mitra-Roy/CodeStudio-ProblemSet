/*
    Unique Paths III :-

    LINK:   https://www.codingninjas.com/codestudio/problems/unique-robot-paths_3657116
*/

#include <iostream>
#include <vector>
using namespace std;

// Array to easily stimulate the moves of visiting adjacent cell.
vector<vector<int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

// Helper function
void robotPathsHelper(int curX, int curY, int &paths, vector<vector<int>> &arr, int left)
{
    // Visited an empty obstacle.
    left--;

    // Dimensions of matrix.
    int n = arr.size();
    int m = arr[0].size();

    // Visit adjacent cells.
    for (auto u : moves)
    {
        // (nextX, nextY) denotes the coordinate of the adjacent cell.
        int nextX = curX + u[0];
        int nextY = curY + u[1];

        // Check for the indices to be inside the bound.
        if (nextX < n && nextY < m && nextX >= 0 && nextY >= 0)
        {
            // Visited the ending cell.
            // Don't make further recursive calls for this case.
            if (arr[nextX][nextY] == 2)
            {
                // Check if visited all the cells except the ending cell.
                if (left == 1)
                    paths++;
            }

            // If the adjacent cell is unvisited.
            else if (arr[nextX][nextY] != -1)
            {

                // Mark it as visited.
                arr[nextX][nextY] = -1;

                // Recursive call.
                robotPathsHelper(nextX, nextY, paths, arr, left);

                // Backtrack.
                arr[nextX][nextY] = 0;
            }
        }
    }
}

int robotPaths(int n, int m, vector<vector<int>> &arr)
{
    // (stX, stY) will denote the starting cell.
    int stX, stY;

    // Variable to store the number of cells to be visited in each path.
    int left = 0;

    // Iterate through all the elements of matrix.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // All the cells not containing obstacles need to be visited.
            if (arr[i][j] != -1)
                left++;

            // Starting cell.
            if (arr[i][j] == 1)
            {
                arr[i][j] = -1;
                stX = i;
                stY = j;
            }
        }
    }

    // Variable to store the count of paths.
    int paths = 0;

    // Initial call to the recursive function.
    robotPathsHelper(stX, stY, paths, arr, left);

    // Finally, return the answer calculated.
    return paths;
}