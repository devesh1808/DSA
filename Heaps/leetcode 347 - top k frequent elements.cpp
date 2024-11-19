class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int ele : nums)
            mp[ele]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};