class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> v;
        deque<int> dq;
        int n = nums.size(), i = 0, j = 0;
        while (j < n)
        {
            if (j - i + 1 < k)
            {
                if (dq.size() == 0)
                    dq.push_back(j);
                else
                {
                    while (!dq.empty() && nums[j] >= nums[dq.back()])
                        dq.pop_back();
                    dq.push_back(j);
                }
                j++;
            }
            else if (j - i + 1 == k)
            {
                if (dq.size() == 0)
                    dq.push_back(j);
                else
                {
                    while (!dq.empty() && nums[j] >= nums[dq.back()])
                        dq.pop_back();
                    dq.push_back(j);
                }
                v.push_back(nums[dq.front()]);
                if (dq.front() == i)
                    dq.pop_front();
                i++, j++;
            }
        }
        return v;
    }
};