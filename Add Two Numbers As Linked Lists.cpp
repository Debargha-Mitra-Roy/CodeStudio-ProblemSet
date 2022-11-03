/*
    Add Two Numbers As Linked Lists :-

    LINK:   https://www.codingninjas.com/codestudio/problems/add-two-numbers-as-linked-lists_1170520
*/

#include <iostream>
#include <vector>
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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // 'NODE1' and 'NODE2' point to the current node of the first and second list, respectively.
    Node *node1 = head1;
    Node *node2 = head2;

    // 'SUM' and 'CARRY' store the sum and carry generated in the current iteration.
    int sum = 0, carry = 0;

    Node *prev = NULL;

    while (node1 != NULL && node2 != NULL)
    {
        // Add the values in the current nodes along with the carry.
        sum = node1->data + node2->data + carry;

        // Store the next node of the sum list in the current node of the first linked list.
        node1->data = sum % 10;

        // Get the new carry.
        carry = sum / 10;

        // Keep track of the previous node.
        prev = node1;

        // Move to the next node
        node1 = node1->next;
        node2 = node2->next;
    }

    // If there are remaining digits in any one of the lists, add them to the sum list.
    if (node1 != NULL || node2 != NULL)
    {
        if (node2 != NULL)
            prev->next = node2;

        node1 = prev->next;

        while (node1 != NULL)
        {
            // Add the values in the current node along with the carry.
            sum = node1->data + carry;

            // Store the next node of the sum list in the current node of the first linked list.
            node1->data = sum % 10;

            // Get the new carry.
            carry = sum / 10;

            // Keep track of the previous node.
            prev = node1;

            // Move to the next node
            node1 = node1->next;
        }
    }

    // Carry is generated from the last iteration. So, add a new node to the sum list.
    if (carry > 0)
        prev->next = new Node(carry);

    // Return the head of the sum list.
    return head1;
}