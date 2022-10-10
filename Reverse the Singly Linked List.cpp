/*
    Reverse the Singly Linked List :-

    LINK:   https://www.codingninjas.com/codestudio/problems/reverse-the-singly-linked-list_799897
*/

#include <iostream>
using namespace std;

/* Following is the class structure of the Node class: */

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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    // Base Case
    if (head == NULL || head->next == NULL)
        return head;

    // Recursion
    LinkedListNode<int> *newHead = reverseLinkedList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}