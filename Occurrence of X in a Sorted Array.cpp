int firstOccurrence(int arr[], int n, int x)
{
    // Initialize start and end pointers
    int startIndex = 0, endIndex = n - 1;

    // Initialize a pointer for starting index of x
    int xStartIndex = -1;

    while (startIndex <= endIndex)
    {
        int mid = startIndex + (endIndex - startIndex) / 2;

        if (arr[mid] >= x)
        {
            // If mid value is x, update index
            if (arr[mid] == x)
                xStartIndex = mid;

            // Search on left
            endIndex = mid - 1;
        }
        else
        {
            // Search on right
            startIndex = mid + 1;
        }
    }

    // Return xStartIndex;
    return xStartIndex;
}

int lastOccurrence(int arr[], int n, int x)
{
    // Initialize start and end pointers
    int startIndex = 0, endIndex = n - 1;

    // Initialize a pointer for starting index of x
    int xEndIndex = -1;

    while (startIndex <= endIndex)
    {
        int mid = startIndex + (endIndex - startIndex) / 2;

        if (arr[mid] > x)
        {
            // Search on left
            endIndex = mid - 1;
        }
        else
        {
            // If mid value is x, update index
            if (arr[mid] == x)
                xEndIndex = mid;

            // Search on right
            startIndex = mid + 1;
        }
    }

    // Return xEndIndex;
    return xEndIndex;
}

int countOccurences(int arr[], int n, int x)
{
    // Initialize start and end position variables for x
    int xStartIndex, xEndIndex;

    xStartIndex = firstOccurrence(arr, n, x);

    // If x is not present
    if (xStartIndex == -1)
        return 0;

    xEndIndex = lastOccurrence(arr, n, x);

    // Total occurrences will be
    int count =  xEndIndex - xStartIndex + 1;

    return count;
}