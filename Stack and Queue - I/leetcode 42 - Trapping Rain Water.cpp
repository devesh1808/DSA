// Solution 1: Using Prefix and Suffix Arrays

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> left(n, 0), right(n, 0);
    left[0] = height[0];
    right[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(height[i], left[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(height[i], right[i + 1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - height[i];
    }
    return ans;
}

// Solution 2: Using 2 pointers

int trap(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int lmax = 0, rmax = 0;
    int ans = 0;
    while (left < right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] > lmax)
                lmax = height[left];
            else
                ans += (lmax - height[left]);
            left++;
        }
        else
        {
            if (height[right] > rmax)
                rmax = height[right];
            else
                ans += (rmax - height[right]);
            right--;
        }
    }
    return ans;
}