// 1. Using Brute force (O(n))

// 2. Using loop by checking square values (O(log n))

long long int floorSqrt(long long int n)
{
    long long int i;
    for (i = 1; i * i <= n; i++)
    {
        if (i * i == n)
            return i;
    }
    return i - 1;
}