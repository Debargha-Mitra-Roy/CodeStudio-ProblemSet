/*
    Print Like A Wave :-

    LINK:   https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;

    for (int col = 0; col < mCols; col++)
    {
        /* for odd index -> Bottom to Top */
        if (col & 1)
        {
            for (int row = nRows - 1; row >= 0; row--)
            {
                ans.push_back(arr[row][col]);
            }
        }

        /* for 0th and even index -> Top to Bottom */
        else
        {
            for (int row = 0; row < nRows; row++)
            {
                ans.push_back(arr[row][col]);
            }
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int nRows;
        cin >> nRows;

        int mCols;
        cin >> mCols;

        vector<vector<int>> arr(nRows);
        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < mCols; j++)
            {
                int value;
                cin >> value;
                arr[i].push_back(value);
            }
        }

        vector<int> answer = wavePrint(arr, nRows, mCols);

        for (auto it : answer)
        {
            cout << it << "\n";
        }
    }

    return 0;
}