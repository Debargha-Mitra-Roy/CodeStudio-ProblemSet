/*
    Delete middle element from stack :-

    LINK:   https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246
*/

#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &inputStack, int count, int size)
{
    // Base case
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();

    inputStack.pop();

    // Recusion
    solve(inputStack, count + 1, size);

    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int n)
{
    int count = 0;

    solve(inputStack, count, n);
}