/*
    Search in a Linked List :-

    LINK:   https://www.codingninjas.com/codestudio/problems/search-in-a-linked-list_975381
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

int searchInLinkedList(LinkedListNode<int> *head, int k)
{
    LinkedListNode<int> *temp = head;

    while (temp != NULL)
    {
        if (temp->data == k)
            return 1;

        temp = temp->next;
    }

    return 0;
}