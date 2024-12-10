int maxArea(vector<int> &h)
{
    int n = h.size();
    int left = 0, right = n - 1, mx = INT_MIN;
    while (left <= right)
    {
        mx = max(mx, min(h[left], h[right]) * (right - left));
        if (h[left] < h[right])
            left++;
        else
            right--;
    }
    return mx;
}