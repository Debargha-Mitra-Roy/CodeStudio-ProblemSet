/*
    Reverse Stack Using Recursion :-

    LINK:   https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875
*/

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int element)
{
    // Base case
    if (s.empty())
    {
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    // Recursive call
    insertAtBottom(s, element);

    s.push(num);
}

void reverseStack(stack<int> &stack)
{
    // Base case
    if (stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    // Recursive call
    reverseStack(stack);

    insertAtBottom(stack, num);
}