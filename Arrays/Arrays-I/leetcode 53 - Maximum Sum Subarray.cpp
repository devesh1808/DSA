int maxSubArray(vector<int> &nums)
{
    int sum = 0, mx = INT_MIN;
    for (int ele : nums)
    {
        sum += ele;
        mx = max(mx, sum);
        if (sum < 0)
            sum = 0;
    }
    return mx;
}