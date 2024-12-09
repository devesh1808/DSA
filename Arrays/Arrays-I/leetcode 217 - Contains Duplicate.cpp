bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> st;
    for (int ele : nums)
        st.insert(ele);
    return st.size() != nums.size();
}