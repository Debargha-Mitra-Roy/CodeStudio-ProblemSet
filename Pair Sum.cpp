/*
    Pair Sum :-

    LINK:   https://www.codingninjas.com/codestudio/problems/pair-sum_697295
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> temp;

                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));

                ans.push_back(temp);
            }
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int n;
    cin >> n;

    int s;
    cin >> s;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> ans = pairSum(arr, s);

    for (auto it : ans)
    {
        for (auto element : it)
        {
            cout << element << " ";
        }
        cout << "\n";
    }

    return 0;
}