/*
    Container With Most Water :-

    LINK:   https://www.codingninjas.com/codestudio/problems/container-with-most-water_873860
*/

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int maximumArea = 0, minimumArea = 0, width = 0;

    while (left < right)
    {
        width = right - left;
        minimumArea = min(height[left], height[right]);
        maximumArea = max(maximumArea, (minimumArea * width));

        if (height[left] < height[right])
            left++;

        else
            right--;
    }

    return maximumArea;
}