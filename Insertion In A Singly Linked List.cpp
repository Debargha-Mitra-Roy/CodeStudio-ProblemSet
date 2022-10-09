/*
    Insertion In A Singly Linked List :-

    LINK:   https://www.codingninjas.com/codestudio/problems/insertion-in-a-singly-linked-list_4609646
*/

#include <iostream>

/* Following is the linkedList class structure: */
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *node = new Node(val);

    node->next = head;
    head = node;
}

void insert(Node *(&head), int n, int pos, int val)
{
    if (pos == 0)
    {
        insertAtHead(head, val);
        return;
    }

    else
    {
        Node *temp1 = new Node(val);
        Node *temp2 = head;

        for (int i = 0; i < pos - 1; i++)
        {
            temp2 = temp2->next;
        }

        temp1->next = temp2->next;
        temp2->next = temp1;
    }
}