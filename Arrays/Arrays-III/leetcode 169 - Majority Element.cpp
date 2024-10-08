int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int ele = -1, cnt = 0;
    for (int val : nums)
    {
        if (val == ele)
            cnt++;
        else if (cnt == 0)
            ele = val, cnt = 1;
        else
            cnt--;
    }
    return ele;
}