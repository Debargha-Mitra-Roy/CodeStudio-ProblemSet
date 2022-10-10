/*
    Reverse Linked List :-

    LINK:   https://www.codingninjas.com/codestudio/problems/reverse-linked-list_920513
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

Node *reverseLinkedList(Node *head)
{
    Node *prevPtr = NULL;
    Node *currPtr = head;
    Node *nextPtr;

    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }

    return prevPtr;
}
