/*
    Check If The String Is A Palindrome :-

    LINK:   https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633
*/

#include <iostream>
#include <cctype>
using namespace std;

char toLowerCase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch;

    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(string s)
{
    int start = 0;
    int end = s.size() - 1;

    while (start <= end)
    {
        if (isalnum(s[start]) == 0)
            start++;

        else if (isalnum(s[end]) == 0)
            end--;

        else if (toLowerCase(s[start]) != toLowerCase(s[end]))
            return false;

        else
        {
            start++;
            end--;
        }
    }

    return true;
}