class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        stack<int> st;
        unordered_map<int, int> mp;
        mp[nums2[n - 1]] = -1;
        st.push(nums2[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && nums2[i] > st.top())
                st.pop();
            int val = (st.empty() ? -1 : st.top());
            mp[nums2[i]] = val;
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};