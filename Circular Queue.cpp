/*
    Circular Queue :-

    LINK:   https://www.codingninjas.com/codestudio/problems/circular-queue_1170058
*/

#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr, front, rear, size;

public:
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        // to check whether queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
            return false;

        else if (front == -1) // first element to push
            front = rear = 0;

        else if (rear == size - 1 && front != 0) // to maintain cyclic nature
            rear = 0;

        else // normal flow
            rear++;

        arr[rear] = value; // push inside the queue
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        if (front == -1) // to check queue is Empty
            return -1;

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) // single element is present
            front = rear = -1;

        else if (front == size - 1) // to maintain cyclic nature
            front = 0;

        else // normal flow
            front++;

        return ans;
    }
};