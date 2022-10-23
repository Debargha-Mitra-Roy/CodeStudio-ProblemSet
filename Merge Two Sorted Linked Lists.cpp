/*
    Merge Two Sorted Linked Lists :-

    LINK:   https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332
*/

#include <iostream>
using namespace std;

/* Following is the linked list node structure. */

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    Node<int> *result;

    // Base Case
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    // Recursive Case
    if (first->data < second->data)
    {
        result = first;
        result->next = sortTwoLists(first->next, second);
    }

    else
    {
        result = second;
        result->next = sortTwoLists(first, second->next);
    }

    return result;
}