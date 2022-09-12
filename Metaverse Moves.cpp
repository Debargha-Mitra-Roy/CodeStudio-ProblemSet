/*
    LINK :  https://www.codingninjas.com/codestudio/contests/codestudio-beginner-contest-2/problems/17771
*/

int isPossibleToReach(int x1, int y1, int x2, int y2, int x, int y) {

    int minX = abs(x1 - x2);
    int minY = abs(y1 - y2);

    if (minX <= x && minY <= y)
        return 1;

    else
        return 0;
}
