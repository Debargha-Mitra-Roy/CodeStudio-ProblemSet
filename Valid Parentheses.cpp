/*
    LINK:   https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104
*/

bool isValidParenthesis(string expression)
{
    int size = expression.size();

    stack<char> s;

    for (int i = 0; i < size; i++)
    {
        char ch = expression[i];

        // if opening bracket, stack.push()
        // if closing bracket, stack.top() & stack.pop()

        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);

        else
        {
            // for closing bracket
            if (!s.empty())
            {
                char top = s.top();

                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                    s.pop();

                else
                    return false;
            }

            else
                return false;
        }
    }

    if (s.empty())
        return true;

    else
        return false;
}