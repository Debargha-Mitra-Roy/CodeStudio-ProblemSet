/*
    Insert a Node at a Specific Position in a Linked List :-

    LINK:   https://www.codingninjas.com/codestudio/library/insert-a-node-at-a-specific-position-in-a-linked-list
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Insert at Head
void insertAtHead(Node *&head, int val)
{
    Node *node = new Node(val);

    node->next = head;
    head = node;
}

// Insert at any Position
void insertAtPosition(Node *&head, int val, int position)
{
    if (position == 1)
    {
        insertAtHead(head, val);
        return;
    }

    else
    {
        Node *temp1 = new Node(val);
        Node *temp2 = head;

        for (int i = 0; i < position - 2; i++)
        {
            temp2 = temp2->next;
        }

        temp1->next = temp2->next;
        temp2->next = temp1;
    }
}

// Display
void display(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = NULL;

    insertAtPosition(head, 2, 1);
    insertAtPosition(head, 3, 2);
    insertAtPosition(head, 4, 3);
    insertAtPosition(head, 5, 4);
    insertAtPosition(head, 6, 5);

    display(head);

    insertAtPosition(head, 1, 4);

    display(head);

    return 0;
}