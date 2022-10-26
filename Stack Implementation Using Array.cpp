/*
    Stack Implementation Using Array :-

    LINK:   https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209
*/

#include <iostream>
#include <vector>
using namespace std;

// Stack class.
class Stack
{
    int *arr;
    int capacity, size, peek;

public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        peek = -1;
        size = 0;
    }

    void push(int num)
    {
        if (size == capacity)
            return;

        peek++;
        size++;
        arr[peek] = num;
    }

    int pop()
    {
        if (peek == -1)
            return -1;

        int num = arr[peek];
        peek--;
        size--;
        return num;
    }

    int top()
    {
        if (peek == -1)
            return -1;

        return arr[peek];
    }

    int isEmpty()
    {
        return (size == 0);
    }

    int isFull()
    {
        return (size == capacity);
    }
};