/*
    Count Nodes within K-distance :-

    LINK:   https://www.codingninjas.com/codestudio/problems/count-nodes-within-k-distance_992849
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS method to find the closest marked nodes
int nodesWithinKDistanceUtil(vector<vector<int>> &graph, bool marked[], int u, vector<int> &distance)
{
    int lastmarked;

    // Queue to store the nodes in order
    queue<int> queue;
    queue.push(u);
    distance[u] = 0;

    while (!queue.empty())
    {
        u = queue.front();
        queue.pop();

        if (marked[u])
            lastmarked = u; // This is a possible answer

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];

            // If not visited yet, then distance[v] = distance[parent] + 1
            if (distance[v] == -1)
            {
                distance[v] = distance[u] + 1;
                queue.push(v);
            }
        }
    }

    // Return the final node
    return lastmarked;
}

int nodesWithinKDistance(vector<vector<int>> &edges, int v, vector<int> &marked, int m, int k)
{
    vector<vector<int>> graph(v);
    int start, end;
    int n = edges.size();
    // Creating the original graph from the edges
    for (int i = 0; i < n; i++)
    {
        start = edges[i][0] - 1;
        end = edges[i][1] - 1;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    bool markNodes[v] = {false};

    for (int i = 0; i < m; i++)
    {
        marked[i] = marked[i] - 1;
    }

    // Storing the marked nodes
    for (int i = 0; i < m; i++)
    {
        markNodes[marked[i]] = true;
    }

    vector<int> temp(v, -1), distanceFromOneExtreme(v, -1), distanceFromOtherExtreme(v, -1);

    start = nodesWithinKDistanceUtil(graph, markNodes, 0, temp);
    end = nodesWithinKDistanceUtil(graph, markNodes, start, distanceFromOneExtreme);

    nodesWithinKDistanceUtil(graph, markNodes, end, distanceFromOtherExtreme);

    int result = 0;
    for (int i = 0; i < v; i++)
    {
        // Increase answer by 1 if distance from both the closest marked nodes is less than k
        if (distanceFromOneExtreme[i] <= k && distanceFromOtherExtreme[i] <= k)
            result++;
    }

    return result;
}
