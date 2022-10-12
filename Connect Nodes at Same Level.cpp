/*
    Connect Nodes at Same Level :-

    LINK:   https://www.codingninjas.com/codestudio/problems/connect-nodes-at-same-level_985347
*/

#include <iostream>
#include <queue>
using namespace std;

/*----------------- Binary Tree node class for reference -----------------*/

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *next;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void connectNodes(BinaryTreeNode<int> *root)
{
    if (!root)
        return;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();

            if (size > 0)
                node->next = q.front();

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
    }
}