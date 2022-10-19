/*
    Find K’th Character of Decrypted String :-

    LINK:   https://www.codingninjas.com/codestudio/problems/find-k-th-character-of-decrypted-string_630508
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

/* Following is the TreeNode class structure */

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode *buildTreeHelper(vector<int> &levelOrder, vector<int> &inOrder, int inStart, int inEnd, int n)
{
    // If 'N' is less than 0, return nullptr.
    if (n <= 0)
        return nullptr;

    // Initialize a TreeNode* 'ROOT' with value 'LEVELORDER[0]'.
    TreeNode *root = new TreeNode(levelOrder[0]);

    // Initialize a variable 'INDEX' with value -1.
    int index = -1;

    // Iterate 'I' in 'INSTART' to 'INEND'
    // Find the index of 'ROOT' in 'INORDER':
    for (int i = inStart; i <= inEnd; i++)
    {
        // If 'ROOT.DATA' is equal to 'INORDER[I], set 'INDEX' as 'I' and break.
        if (root->data == inOrder[i])
        {
            index = i;
            break;
        }
    }

    // Initialize a HashSet 'SET'.
    set<int> s;

    // Iterate 'I' in 'INSTART' to 'INDEX'
    for (int i = inStart; i < index; i++)
    {
        // Add 'INORDER[I]' to 'SET'.
        s.insert(inOrder[i]);
    }

    // Initialize an array 'LEFTLEVEL' of size 'SET.SIZE'.
    vector<int> leftLevel(s.size());

    // Initialize an array 'RIGHTLEVEL' of size 'INEND' - 'INSTART' - 'SET.SIZE'.
    vector<int> rightLevel(inEnd - inStart - s.size());

    // Initialize variables 'LEFT' and 'RIGHT' with value 0.
    int left = 0, right = 0;

    // Iterate 'I' in 1 to 'N':
    for (int i = 1; i < n; i++)
    {

        // If 'S' contains 'LEVELORDER[I]', set 'LEFTLEVEL[LEFT++]' as 'LEVELORDER[I]'.
        if (s.find(levelOrder[i]) != s.end())
            leftLevel[left++] = levelOrder[i];

        // Otherwise set 'RIGHTLEVEL[RIGHT++]' as 'LEVELORDER[I]'.
        else
            rightLevel[right++] = levelOrder[i];
    }

    // Recursively create left subtree.
    root->left = buildTreeHelper(leftLevel, inOrder, inStart, index - 1, index - inStart);

    // Recursively create right subtree.
    root->right = buildTreeHelper(rightLevel, inOrder, index + 1, inEnd, inEnd - index);

    // Return root.
    return root;
}

TreeNode *getTreeFromInorderAndLevelorder(int n, vector<int> &inOrder, vector<int> &levelOrder)
{
    TreeNode *root = nullptr;

    // Call buildTreeHelper function
    return buildTreeHelper(levelOrder, inOrder, 0, n - 1, n);
}