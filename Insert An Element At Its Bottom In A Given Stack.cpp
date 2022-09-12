/*
    Insert An Element At Its Bottom In A Given Stack :-

    LINK:   https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166
*/

#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    solve(s, x);

    s.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);

    return myStack;
}