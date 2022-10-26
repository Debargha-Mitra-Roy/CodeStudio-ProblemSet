/*
    Delete Kth node From End :-

    LINK:   https://www.codingninjas.com/codestudio/problems/delete-kth-node-from-end-in-linked-list_799912
*/

#include <iostream>
using namespace std;

/* Following is the class structure of the LinkedListNode class: */

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *removeKthNode(LinkedListNode<int> *head, int K)
{
    if (head == NULL || K == 0)
        return head;

    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    for (int i = 0; i < K; i++)
    {
        // If head is the Kth node from end of Linked List.
        if (fast->next == NULL)
        {
            LinkedListNode<int> *next = head->next;
            head->next = NULL;
            head = next;

            return head;
        }

        else
            fast = fast->next;
    }

    // Moving both slow and fast pointer with same speed.
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Removing the Kth node from end of Linked List.
    slow->next = slow->next->next;

    return head;
}