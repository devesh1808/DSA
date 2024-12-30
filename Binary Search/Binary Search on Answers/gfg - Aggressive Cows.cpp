class Solution
{
public:
    int func(vector<int> &s, int m, int k)
    {
        int c = 1;
        int val = s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] - val >= m)
                c++, val = s[i];
        }
        return c;
    }

    int aggressiveCows(vector<int> &s, int k)
    {

        // Write your code here
        sort(s.begin(), s.end());
        int n = s.size();
        int ans = -1;
        int low = 0, high = s[n - 1] - s[0];
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int cows = func(s, mid, k);
            if (cows < k)
                high = mid - 1;
            else
            {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};