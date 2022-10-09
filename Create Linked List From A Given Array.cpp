/*
    Create Linked List From A Given Array :-

    LINK:   https://www.codingninjas.com/codestudio/library/create-linked-list-from-a-given-array
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

// Insertion
void insert(Node *&head, int val)
{
    Node *node = new Node(val);

    if (head == NULL)
    {
        head = node;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
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
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = NULL;
    
    for (int i = 0; i < n; i++)
    {
        insert(head, arr[i]);
    }

    display(head);

    return 0;
}