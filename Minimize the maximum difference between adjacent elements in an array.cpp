/*
    Minimize the maximum difference between adjacent elements in an array :-

    LINK:   https://www.codingninjas.com/codestudio/problems/minimize-the-maximum-difference-between-adjacent-elements-in-an-array_893177
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findMinAnswer(vector<int> diff, int k)
{
    int n = diff.size();

    // We make a deque of indices such that the values in the deque are non increasing at any point.
    deque<int> dq;

    for (int i = 0; i < k; ++i)
    {
        while (!dq.empty() && diff[dq.back()] <= diff[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    int minAnswer = diff[dq.front()];

    for (int i = k; i < n; ++i)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() && diff[dq.back()] <= diff[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        minAnswer = min(minAnswer, diff[dq.front()]);
    }

    return minAnswer;
}

int maxAdjDifference(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> diff(n - 1);

    for (int i = 0; i < n - 1; ++i)
    {
        diff[i] = arr[i + 1] - arr[i];
    }

    return findMinAnswer(diff, n - k - 1);
}