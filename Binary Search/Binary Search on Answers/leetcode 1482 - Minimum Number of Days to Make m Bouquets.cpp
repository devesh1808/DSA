int func(vector<int> nums, int k, int days)
{
    int cnt = 0, bk = 0;
    for (int ele : nums)
    {
        if (ele <= days)
        {
            cnt++;
            if (cnt == k)
            {
                bk++;
                cnt = 0;
            }
        }
        else
            cnt = 0;
    }
    return bk;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    if (m > n / k)
        return -1; // (m*k >n == m>n/k)
    int mx = *max_element(bloomDay.begin(), bloomDay.end());
    int low = 0, high = mx;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int bouquets = func(bloomDay, k, mid);
        if (bouquets < m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}