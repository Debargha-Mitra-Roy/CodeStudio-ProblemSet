long long transactions(vector<int> &money) {

    long long int maxx = 0;

    if (money[0] > 0)
        maxx = money[0];

    long long int sum = 0;

    for (int  i = 0; i < money.size(); i++)
    {
        sum = sum + money[i];

        maxx = max(maxx, sum);
    }

    return maxx;
}