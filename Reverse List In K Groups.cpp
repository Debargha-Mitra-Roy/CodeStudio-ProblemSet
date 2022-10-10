/*
    Reverse List In K Groups :-

    LINK:   https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644
*/

#include <iostream>
using namespace std;

/* Following is the Linked List node structure */

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

Node *kReverse(Node *head, int k)
{
    Node *prevPtr = NULL;
    Node *currPtr = head;
    Node *nextPtr;

    int count = 0;

    while (currPtr != NULL && count < k)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;

        count++;
    }

    if (nextPtr != NULL)
        head->next = kReverse(nextPtr, k);

    return prevPtr;
}