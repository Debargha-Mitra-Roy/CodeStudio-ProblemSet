/*
    Lucky String :-
    
    LINK:   https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-8/problems/16613
*/

#include <iostream>
using namespace std;

int makeLucky(string s, int n)
{
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i - 1] && s[i] == s[i + 1])
            count++;
    }

    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        cout << makeLucky(s, n) << "\n";
    }

    return 0;
}