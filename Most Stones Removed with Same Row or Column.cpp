/*
    Longest Route :-

    LINK:   https://www.codingninjas.com/codestudio/problems/longest-route_1170525
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Find the representative of the set.
int find(int n, vector<int> &parent)
{
    if (parent[n] == n)
        return n;

    return parent[n] = find(parent[n], parent);
}

// Unite the sets.
void unite(int a, int b, vector<int> &parent)
{
    parent[find(a, parent)] = find(b, parent);
}

int removeStones(vector<vector<int>> &stones)
{
    vector<int> parent;
    unordered_map<int, vector<int>> rowMap, colMap;

    for (int i = 0; i < stones.size(); i++)
    {
        rowMap[stones[i][0]].push_back(i);
        colMap[stones[i][1]].push_back(i);
    }

    for (int i = 0; i < stones.size(); i++)
    {
        parent.push_back(i);
    }

    for (int i = 0; i < stones.size(); i++)
    {
        for (int j : rowMap[stones[i][0]])
        {
            unite(i, j, parent);
        }

        for (int j : colMap[stones[i][1]])
        {
            unite(i, j, parent);
        }
    }

    unordered_set<int> unique;

    for (int n : parent)
    {
        unique.insert(find(n, parent));
    }

    return (stones.size() - unique.size());
}