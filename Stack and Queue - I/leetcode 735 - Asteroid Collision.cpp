class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        for (int ele : asteroids)
        {
            if (ele > 0)
                st.push(ele);
            else
            {
                while (!st.empty() && st.top() > 0 && (-1 * ele) > st.top())
                    st.pop();
                if (st.empty() || st.top() < 0)
                    st.push(ele);
                if (!st.empty() && st.top() == (-1 * ele))
                    st.pop();
            }
        }
        vector<int> v;
        while (!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};