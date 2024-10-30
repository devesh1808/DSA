class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int mxLen = 1;
        for (int ele : nums)
        {
            if (st.find(ele - 1) == st.end())
            {
                int val = ele;
                int len = 0;
                while (st.find(val) != st.end())
                {
                    len++;
                    val++;
                    mxLen = max(mxLen, len);
                }
            }
        }
        return mxLen;
    }
};