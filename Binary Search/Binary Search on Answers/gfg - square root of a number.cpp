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

// 3. Using Binary Search (log n)

long long int floorSqrt(long long int n)
{
    long long int low = 1, high = n;
    while (low <= high)
    {
        long long int mid = (low + high) / 2;
        long long int squareValue = mid * mid;
        if (squareValue == n)
            return mid;
        else if (squareValue > n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return high;
}