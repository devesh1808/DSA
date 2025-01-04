vector<int> nse(vector<int> &arr, int n)
{

    stack<int> st;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> pse(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int res = 0;
    int n = heights.size();
    vector<int> nextSmaller = nse(heights, n);
    vector<int> prevSmaller = pse(heights, n);
    for (int i = 0; i < n; i++)
    {
        int width = nextSmaller[i] - prevSmaller[i] - 1;
        res = max(res, width * heights[i]);
    }
    return res;
}