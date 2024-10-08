vector<vector<int>> merge(vector<vector<int>> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr;
    sort(arr.begin(), arr.end());
    vector<int> temp = arr[0];
    vector<vector<int>> ans;
    for (int i = 1; i < n; i++)
    {
        vector<int> v = arr[i];
        if (temp[1] >= v[0])
        {
            temp[1] = max(temp[1], v[1]);
        }
        else
        {
            ans.push_back(temp);
            temp = v;
        }
    }
    ans.push_back(temp);
    return ans;
}