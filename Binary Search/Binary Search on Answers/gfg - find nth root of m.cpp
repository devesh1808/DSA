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