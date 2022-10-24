/*
    Closest Coprime Ancestor :-

    LINK:   https://www.codingninjas.com/codestudio/problems/closest-coprime-ancestor_1464025
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>
using namespace std;

// Maximum possible node value.
const int MAX_NODE_VAL = 20;

// Function to find the closest coprime ancestor of every node.
void dfs(vector<int> &nodes, vector<vector<int>> &adjList, vector<vector<int>> &coprimeLookup, vector<pair<int, int>> &ancestors, int current, int parent, int depth, vector<int> &result)
{
    int closestAncestor = -1, maxDepth = -1, value = nodes[current];

    // Checking among all the nodes which are coprime with the 'CURRENT' node.
    for (int coprime : coprimeLookup[value])
    {
        // If the 'COPRIME' is closer coprime ancestor than its previous ancestor, then update the closest coprime ancestor for the 'CURRENT' node.
        if (ancestors[coprime].second > maxDepth)
        {
            closestAncestor = ancestors[coprime].first;
            maxDepth = ancestors[coprime].second;
        }
    }

    // Store the closest coprime ancestor in the 'RESULT' array for the 'CURRENT' node.
    result[current] = closestAncestor;

    // Extract the recent value from the 'ANCESTORS' array for the 'CURRENT' node.
    pair<int, int> lastValue = ancestors[value];

    // Update the 'ANCESTORS' array for the 'CURRENT' node so that it can be considered as an ancestor for its children.
    ancestors[value] = {current, depth};

    // Recursively update the closest coprime ancestor for every children of the 'CURRENT' node.
    for (int childNode : adjList[current])
    {
        if (childNode != parent)
            dfs(nodes, adjList, coprimeLookup, ancestors, childNode, current, depth + 1, result);
    }

    // Put back the 'LASTVALUE' in ancestor array for the 'CURRENT' node.
    ancestors[value] = lastValue;
}

vector<int> closestCoprimeAncestor(vector<int> &nodes, vector<vector<int>> &edges, int n)
{
    // To store the closest coprime ancestor for every node.
    vector<int> result(n);

    // To store the list of ancestors at every level of the tree.
    vector<pair<int, int>> ancestors(MAX_NODE_VAL + 1, {-1, -1});

    // Adjacency list representation of the tree.
    vector<vector<int>> adjList(n);

    // To store the list of coprimes for every integer.
    vector<vector<int>> coprimeLookup(MAX_NODE_VAL + 1);
    for (int i = 1; i <= MAX_NODE_VAL; i++)
    {
        for (int j = 1; j <= MAX_NODE_VAL; j++)
        {
            if (__gcd(i, j) == 1)
                coprimeLookup[i].push_back(j);
        }
    }

    for (vector<int> &edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    // Perform 'DFS' and store the closest coprime ancestor for every node in 'RESULT'.
    dfs(nodes, adjList, coprimeLookup, ancestors, 0, -1, 0, result);

    return result;
}