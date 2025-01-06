class Solution
{
public:
    int leastInterval(vector<char> &nums, int n)
    {
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int ele : nums)
        {
            mp[ele]++;
            cnt = max(cnt, mp[ele]);
        }
        int time = (cnt - 1) * (n + 1);
        for (auto it : mp)
        {
            if (it.second == cnt)
                time++;
        }
        return time > nums.size() ? time : nums.size();
    }
};