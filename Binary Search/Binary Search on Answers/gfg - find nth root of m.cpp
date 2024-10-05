// Code 1 : Using loop (n*logm)

int NthRoot(int n, int m)
{
    int nthVal;
    for (int i = 1; nthVal <= m; i++)
    {
        nthVal = 1;
        for (int j = 1; j <= n; j++)
        {
            nthVal = nthVal * i;
        }
        if (nthVal == m)
            return i;
    }
    return -1;
}

// Code 2 : Using Binary Search

int NthRoot(int n, int m)
{
    long long low = 1, high = m;
    while (high >= low)
    {
        long long mid = (low + high) / 2;
        if (pow(mid, n) == m)
            return mid;
        else if (pow(mid, n) > m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}