class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int j = 0, mx = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            while (mp[s[i]] > 1)
            {
                mp[s[j]]--;
                j++;
            }
            mx = max(mx, i - j + 1);
        }
        return mx;
    }
};