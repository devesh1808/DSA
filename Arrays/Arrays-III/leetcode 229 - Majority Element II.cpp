vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int ele1 = INT_MIN, ele2 = INT_MIN, cnt1 = 0, cnt2 = 0;
    for (int val : nums)
    {
        if (val == ele1)
            cnt1++;
        else if (val == ele2)
            cnt2++;
        else if (cnt1 == 0)
            ele1 = val, cnt1 = 1;
        else if (cnt2 == 0)
            ele2 = val, cnt2 = 1;
        else
            cnt1--, cnt2--;
    }
    cnt1 = 0, cnt2 = 0;
    for (int val : nums)
    {
        if (val == ele1)
            cnt1++;
        if (val == ele2)
            cnt2++;
    }
    if (cnt1 > (n / 3) && cnt2 > (n / 3))
        return {ele1, ele2};
    if (cnt1 > (n / 3))
        return {ele1};
    if (cnt2 > (n / 3))
        return {ele2};
    return {};
}