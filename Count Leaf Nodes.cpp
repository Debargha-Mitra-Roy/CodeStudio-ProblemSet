/*
    Count Leaf Nodes :-

    LINK:   https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055
*/

#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void inOrderTraversal(BinaryTreeNode<int> *root, int &count)
{
    // Base case
    if (root == NULL)
        return;

    inOrderTraversal(root->left, count); // left

    // count leaf node
    if (root->left == NULL && root->right == NULL)
        count++;

    inOrderTraversal(root->right, count); // right
}

int noOfLeafNodes(BinaryTreeNode<int> *root)
{

    int count = 0;

    inOrderTraversal(root, count);

    return count;
}