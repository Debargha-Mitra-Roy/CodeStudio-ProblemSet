/*
    Reverse Nodes in k-Group :-

    LINK:   https://www.codingninjas.com/codestudio/problems/reverse-blocks_763406
*/

#include <iostream>
using namespace std;

/* Following is the class structure of the Node class: */

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *reverseKElements(Node *head, int n, int b[], int idx)
{
    // Base case: List is empty or entire block array have been considered.
    if (head == NULL || idx >= n)
        return head;

    // K will be the size of the current block.
    int K = b[idx];

    // Just move to the next block if size of the current block is zero.
    if (K == 0)
        return reverseKElements(head, n, b, idx + 1);

    Node *currPtr = head, *prevPtr = NULL, *nextPtr = NULL;

    // Variable to keep track of the number of nodes reversed in the current block.
    int count = 0;

    // Reverse nodes until end of list is reached or current block has been reversed.
    while (currPtr != NULL && count < K)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;

        count++;
    }

    // Reverse the next block.
    head->next = reverseKElements(nextPtr, n, b, idx + 1);

    return prevPtr;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    // If linked list is empty, return head of the linked list.
    if (head == NULL)
        return NULL;

    // Calling reverseKElements function to modify the given linked list.
    head = reverseKElements(head, n, b, 0);

    // Return the head of the linked list.
    return head;
}