/*
    Strange Numbers :-

    LINK:   https://www.codingninjas.com/codestudio/problems/strange-numbers_1266132
*/

#include <iostream>
#include <vector>
using namespace std;

bool isStrangeNumber(int currNumber)
{
    int rotatedNumber = 0;
    int dummy = currNumber;

    // Run a loop while ‘dummy’ is greater than 0.
    while (dummy > 0)
    {
        // Declare a variable ‘currDigit’ and initialize it with the rightmost digit of ‘dummy’
        int currDigit;
        currDigit = dummy % 10;

        // Remove the rightmost digit of ‘dummy’
        dummy = dummy / 10;

        // Rotate the ‘currDigit’ by 180 degrees.
        if (currDigit == 6)
            currDigit = 9;

        else if (currDigit == 9)
            currDigit = 6;

        // Append the ‘currDigit’ to ‘rotatedNumber’
        rotatedNumber = rotatedNumber * 10 + currDigit;
    }

    if (currNumber != rotatedNumber)
        return true; // As the current number follows properties of a strange number.

    else
        return false; // As the current number does not follow properties of a strange number as after rotating, the number must be different.
}

int depthFirstSearch(int &n, int currNumber)
{

    int answer = 0;

    // If ‘currNumber’ is a strange number, Increment ‘answer’
    if (isStrangeNumber(currNumber) == true)
        answer = answer + 1;

    vector<int> digits = {0, 1, 6, 8, 9};

    // Iterate over all digit in 'digits'
    for (int i = 0; i < digits.size(); i++)
    {
        int appendedNumber;
        appendedNumber = currNumber * 10 + digits[i];

        // If ‘appendedNumber’ lies between 1 and ‘N’ inclusive
        if (appendedNumber >= 1 && appendedNumber <= n)
        {
            int currAnswer;
            currAnswer = depthFirstSearch(n, appendedNumber);

            // Add ‘currAnswer’ to the ‘answer’
            answer = answer + currAnswer;
        }
    }

    return answer;
}

int strangeNumbers(int n)
{
    int countStrange;
    countStrange = depthFirstSearch(n, 0);
    
    return countStrange;
}
