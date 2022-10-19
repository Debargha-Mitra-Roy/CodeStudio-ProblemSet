/*
    Find K’th Character of Decrypted String :-

    LINK:   https://www.codingninjas.com/codestudio/problems/find-k-th-character-of-decrypted-string_630508
*/

#include <iostream>
using namespace std;

char kThCharaterOfDecryptedString(string s, long long int k)
{
    char ans = 'a';
    long long int sum = 0;
    int len = s.length();
    int i = 0;

    while (i < len)
    {
        string temp = "";

        while (i < len && s[i] >= 'a' && s[i] <= 'z')
        {
            temp += s[i];
            i++;
        }

        long long int temp2 = 0;

        while (i < len && s[i] >= '0' && s[i] <= '9')
        {
            temp2 = temp2 * 10 + (s[i] - '0');
            i++;
        }

        if (k <= sum + temp2 * temp.length())
        {
            int len2 = temp.length();
            k -= sum;
            k = k % len2;

            if (k == 0)
                ans = temp[len2 - 1];

            else
                ans = temp[k - 1];

            return ans;
        }

        sum += temp2 * temp.length();
    }

    return ans;
}