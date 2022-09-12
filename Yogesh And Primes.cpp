/*
    Yogesh And Primes :-

    LINK:   https://www.codingninjas.com/codestudio/problems/yogesh-and-primes_16331
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    vector<int> isPrime(int a, int b, int k)
    {
        vector<int> ans;

        for (int i = a; i <= b; i++)
        {
            if (i == 1 || i == 0)
                continue;
                
            int flag = 1;

            for (int j = 2; j <= sqrt(i); ++j)
            {
                if (i % j == 0)
                {
                    flag = 0;
                    break;
                }
            }
            
            if (flag == 1)
                cout << i << " ";
        }

        return ans;
    }

    int primeSieve(int a, int b, int k)
    {
        vector<int> prime = isPrime(a, b, k);

        int count = prime.size();

        if (count < k)
            return -1;

        else
            return prime[k - 1];
    }
};