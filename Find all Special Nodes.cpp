/*
    Find all Special Nodes :-

    LINK:   https://www.codingninjas.com/codestudio/problems/find-all-special-nodes_1376447
*/

#include <iostream>
#include <vector>
using namespace std;

/* Following is the TreeNode class structure. */
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void helper(TreeNode<int> *root, TreeNode<int> *parent, vector<int> &output)
{
    if (root == NULL)
        return;

    if (parent != NULL && parent->left == root && parent->right == NULL)
        output.push_back(root->val);

    else if (parent != NULL && parent->left == NULL && parent->right == root)
        output.push_back(root->val);

    helper(root->left, root, output);
    helper(root->right, root, output);
}

vector<int> findSpecialNodes(TreeNode<int> *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    TreeNode<int> *parent = NULL;

    helper(root, parent, ans);

    return ans;
}