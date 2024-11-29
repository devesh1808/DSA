// Using Recursion

void func(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    func(root->left, ans);
    ans.push_back(root->val);
    func(root->right, ans);
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    func(root, ans);
    return ans;
}

// Using Iteration (Stack)

vector<int> inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *curr = root;
    while (!st.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        curr = curr->right;
    }
    return ans;
}