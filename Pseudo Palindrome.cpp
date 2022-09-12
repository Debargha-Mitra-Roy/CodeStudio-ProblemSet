int canBePalindrome(int n, string s) {

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[n - i - 1])
            continue;

        else
        {
            if (s[i] == s[n - i - 2])
                continue;

            else
                count++;
        }
    }

    if (count > 1)
        return 0;

    else
        return 1;
}
