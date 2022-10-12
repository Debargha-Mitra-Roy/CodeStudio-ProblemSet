/*
    Append Nodes :-

    LINK:   https://www.codingninjas.com/codestudio/problems/append-nodes_763407
*/

#include <iostream>
using namespace std;

/* Following is the class structure of the Node class:: */

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *addNodes(Node *head, int n, int m)
{
    if (head == NULL || n == 0 || m == 0)
        return head;

    Node *prevPtr = NULL;
    Node *currPtr = head;

    while (currPtr != NULL)
    {
        for (int i = 0; i < m && currPtr != NULL; i++)
        {
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }

        if (currPtr == NULL)
            return head;

        int sum = 0;

        for (int i = 0; i < n && currPtr != NULL; i++)
        {
            sum += currPtr->data;
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }

        prevPtr->next = new Node(sum);
        prevPtr->next->next = currPtr;
    }

    return head;
}