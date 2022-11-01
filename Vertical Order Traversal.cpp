/*
    Vertical Order Traversal :-

    LINK:   https://www.codingninjas.com/codestudio/problems/vertical-order-traversal_920533
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

/* Following is the Binary Tree node class */

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<vector<int>> tempAns;
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, vector<int>> mpp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        TreeNode<int> *node = it.first;
        int line = it.second;
        mpp[line].push_back(node->data);

        if (node->left != NULL)
            q.push(make_pair(node->left, line - 1));

        if (node->right != NULL)
            q.push(make_pair(node->right, line + 1));
    }

    for (auto it : mpp)
    {
        tempAns.push_back(it.second);
    }

    for (int i = 0; i < tempAns.size(); i++)
    {
        for (int j = 0; j < tempAns[i].size(); j++)
        {
            ans.push_back(tempAns[i][j]);
        }
    }

    return ans;
}