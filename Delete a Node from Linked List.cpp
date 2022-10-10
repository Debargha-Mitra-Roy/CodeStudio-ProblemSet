/*
    Delete a Node from Linked List :-

    LINK:   https://www.codingninjas.com/codestudio/problems/delete-node-in-ll_5881
*/

/* Following is the class structure of the Node class: */

#include <iostream>
using namespace std;

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

int size(Node *&head)
{
    Node *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

Node *deleteNode(Node *head, int pos)
{
    if (head == NULL)
        return NULL;

    if (pos >= size(head))
        return head;

    if (pos == 0)
        return head->next;

    Node *temp = head;

    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;

    return head;
}