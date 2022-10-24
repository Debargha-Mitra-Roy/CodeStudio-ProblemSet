/*
    Queue Using Stack :-

    LINK:   https://www.codingninjas.com/codestudio/problems/queue-using-stack_799482
*/

#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    // Define the data members(if any) here.
    stack<int> s1;
    stack<int> s2;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        int ans;

        if (!s1.empty())
        {
            ans = s1.top();
            s1.pop();
        }

        else
            ans = -1;

        return ans;
    }

    int peek()
    {
        // Implement the peek() function here.
        if (s1.empty())
            return -1;

        else
            return s1.top();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        return s1.empty();
    }
};