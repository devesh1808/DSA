
int func(vector<int> nums, int mid)
{
    int time = 0;
    for (int ele : nums)
    {
        if ((ele % mid) == 0)
            time += ((ele / mid));
        else
            time += (ele / mid) + 1;
    }
    return time;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int n = piles.size();
    int mx = *max_element(piles.begin(), piles.end());
    if (n == h)
        return mx;
    int low = 1, high = mx;
    while (low < high)
    {
        int mid = (low + high) / 2;
        int time = func(piles, mid);
        if (time <= h)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}