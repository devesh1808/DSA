class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        // code here
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0, xr = 0;
        for (int ele : arr)
        {
            xr = xr ^ ele;
            int x = xr ^ k;
            cnt += mp[x];
            mp[xr]++;
        }
        return cnt;
    }
};