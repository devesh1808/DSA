vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> left(n), right(n);
    left[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] * nums[i];
    }
    right[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            ans[i] = right[i + 1];
        else if (i == n - 1)
            ans[i] = left[i - 1];
        else
            ans[i] = left[i - 1] * right[i + 1];
    }
    return ans;
}