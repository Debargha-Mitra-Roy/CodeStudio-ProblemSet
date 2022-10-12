/*
    Cycle Detection in a Singly Linked List :-

    LINK:   https://www.codingninjas.com/codestudio/problems/cycle-detection-in-a-singly-linked-list_628974
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

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}