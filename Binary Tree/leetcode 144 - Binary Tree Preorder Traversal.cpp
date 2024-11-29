// Using Recursion

void func(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    ans.push_back(root->val);
    func(root->left, ans);
    func(root->right, ans);
}
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    func(root, ans);
    return ans;
}

// Using Iteration (Stack)

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<TreeNode *> st;
    TreeNode *curr = root;
    while (!st.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            ans.push_back(curr->val);
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        curr = curr->right;
    }
    return ans;
}