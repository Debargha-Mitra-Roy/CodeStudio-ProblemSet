/*
    Sort An Array of 0s, 1s and 2s :-

    LINK:   https://www.codingninjas.com/codestudio/problems/sort-an-array-of-0s-1s-and-2s_892977
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode<T> *next;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void storeInorder(TreeNode<int> *root, unordered_set<int> &inOrder)
{
    if (root == NULL)
        return;

    storeInorder(root->left, inOrder);
    inOrder.insert(root->data);
    storeInorder(root->right, inOrder);
}

// Function to check if the two BSTs contain same set  of elements.
bool checkBSTs(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Base cases
    if (root1 == NULL && root2 == NULL)
        return true;

    if ((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
        return false;

    unordered_set<int> inOrder1;
    unordered_set<int> inOrder2;

    storeInorder(root1, inOrder1);
    storeInorder(root2, inOrder2);

    // If size of both set is not same then return false.
    if (inOrder1.size() != inOrder2.size())
        return false;

    // Check if all the elements are same in both the set.
    return (inOrder1 == inOrder2);
}