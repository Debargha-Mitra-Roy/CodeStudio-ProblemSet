/*
    Leaders in an array :-

    LINK:   https://www.codingninjas.com/codestudio/problems/most-stones-removed-with-same-row-or-column_1376597
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> findLeaders(vector<int> elements, int n)
{
    int maximum = elements[n - 1];

    vector<int> answer;

    // Rightmost element is always a leader.
    answer.push_back(maximum);

    for (int i = n - 2; i >= 0; i--)
    {
        // If current element is greater than maximum.
        if (maximum < elements[i])
        {
            maximum = elements[i];
            answer.push_back(maximum);
        }
    }

    // To get original order.
    reverse(answer.begin(), answer.end());

    return answer;
}