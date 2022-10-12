/*
    Deletion In Doubly Linked List :-

    LINK:   https://www.codingninjas.com/codestudio/problems/deletion-in-doubly-linked-list_4609672
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

void deleteNode(Node *(&head), int pos)
{
    if (head == NULL)
        return;

    if (pos == 0)
    {
        head = head->next;
        head->prev = NULL;
        return;
    }

    Node *temp = head;

    int count = 1;

    while (temp != NULL && count < pos)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next->next == NULL)
        temp->next = NULL;

    else
    {
        Node *a = temp->next->next;
        temp->next = a;
        a = temp->prev;
    }
}