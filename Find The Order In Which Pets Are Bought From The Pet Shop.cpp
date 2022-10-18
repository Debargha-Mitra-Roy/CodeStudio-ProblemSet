/*
    Find The Order In Which Pets Are Bought From The Pet Shop :-

    LINK:   https://www.codingninjas.com/codestudio/problems/find-the-order-in-which-pets-are-bought-from-the-pet-shop_1199010
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(vector<vector<int>> arr, int n)
{
    queue<pair<int, int>> cat;
    queue<pair<int, int>> dog;
    vector<int> ans;

    int time = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i][0] == 1)
        {
            if (arr[i][2] == 0)
                dog.push({arr[i][1], time++});

            else
                cat.push({arr[i][1], time++});
        }

        else
        {
            if (arr[i][1] == 0)
            {
                ans.push_back(dog.front().first);
                dog.pop();
            }

            else if (arr[i][1] == 1)
            {
                ans.push_back(cat.front().first);
                cat.pop();
            }

            else
            {
                if (dog.size() == 0)
                {
                    ans.push_back(cat.front().first);
                    cat.pop();
                }

                else if (cat.size() == 0)
                {
                    ans.push_back(dog.front().first);
                    dog.pop();
                }

                else
                {
                    if (dog.front().second < cat.front().second)
                    {
                        ans.push_back(dog.front().first);
                        dog.pop();
                    }

                    else
                    {
                        ans.push_back(cat.front().first);
                        cat.pop();
                    }
                }
            }
        }
    }

    return ans;
}