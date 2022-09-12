/*
    Replace Spaces :-

    LINK:   https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172
*/

#include <iostream>
using namespace std;

string replaceSpaces(string &str)
{
    int n = str.size();

    string temp = "";

    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }

        else
            temp.push_back(str[i]);
    }

    return temp;
}