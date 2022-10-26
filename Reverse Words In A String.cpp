/*
    Reverse Words In A String :-

    LINK:   https://www.codingninjas.com/codestudio/problems/reverse-words_696444
*/

#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str)
{
    str += " ";

    int n = str.size();

    stack<string> st;
    string word = "";

    for (int i = 0; i < n; i++)
    {
        if (str[i] != ' ')
            word += str[i];

        else
        {
            if (word != "")
                st.push(word);

            word = "";
        }
    }

    string ans = "";

    while (!st.empty())
    {
        ans += st.top() + " ";
        st.pop();
    }

    return ans;
}