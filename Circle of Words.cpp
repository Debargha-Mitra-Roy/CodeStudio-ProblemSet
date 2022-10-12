/*
    Circle of Words :-

    LINK:   https://www.codingninjas.com/codestudio/problems/circle-of-words_1754952
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to traverse the graph.
void dfs(vector<vector<int>> &adj, int node, vector<bool> &vis)
{

    // Current node is visited.
    vis[node] = true;

    // Calling dfs function for every child that is not visited.
    for (int child : adj[node])
    {
        if (vis[child] == false)
            dfs(adj, child, vis);
    }
}

// Function to check whether every node is visited or not.
bool check(vector<vector<int>> &adj, vector<bool> &vis)
{

    for (int i = 0; i < vis.size(); i++)
    {

        // If the current node exists and is not visited, then return false.
        if (adj[i].size() != 0 && vis[i] == false)
            return false;
    }

    return true;
}

// Function to make transpose of a graph.
vector<vector<int>> transpose(vector<vector<int>> &adj, int n)
{
    // Initialising a new Graph object.
    vector<vector<int>> adj_transpose(n);

    // Reversing the edges to make transpose.
    for (int i = 0; i < n; i++)
    {
        for (int j : adj[i])
        {
            adj_transpose[j].push_back(i);
        }
    }

    return adj_transpose;
}

// Function to check whether all the nodes in a graph form a strongly connected component or not.
bool isStronglyConnected(vector<vector<int>> &adj, int n)
{

    // To store the information whether a node is already visited or not.
    vector<bool> vis(n, false);

    // Calling dfs function with a node which exists in the graph.
    int i;

    for (i = 0; i < n; i++)
    {
        if (adj[i].size() != 0)
        {
            dfs(adj, i, vis);
            break;
        }
    }

    // If all the nodes are not visited, return false.
    if (check(adj, vis) == false)
        return false;

    // Reinitialising vis vector with false.
    for (int j = 0; j < n; j++)
    {
        vis[i] = false;
    }

    // Creating transpose of the graph.
    vector<vector<int>> adj_transpose = transpose(adj, n);

    // Calling dfs on the g_transpose with node i which exists in the graph.
    dfs(adj_transpose, i, vis);

    // Checking whether every node is visted or not.
    return check(adj_transpose, vis);
}

bool circleOfWords(vector<string> &words)
{

    // Initialising a vector of vectors, to store the adjacency list, of size 26 since there are 26 capital alphabets.
    vector<vector<int>> adj(26);

    // Creating two vectors to keep track ofin-degree and out-degree.
    vector<int> in(26, 0), out(26, 0);

    // For each word in the vector of words,add an edge from the first character to the last character.
    for (string s : words)
    {
        int u = s.front() - 'A';
        int v = s.back() - 'A';

        adj[u].push_back(v);

        in[v]++;
        out[u]++;
    }

    // If for any node, in-degree is not equal to out-degree, return false.
    for (int i = 0; i < 26; i++)
    {
        if (out[i] != in[i])
            return false;
    }

    // Check whether all the nodes form a strongly connected component or not.
    if (isStronglyConnected(adj, 26))
        return true;

    return false;
}