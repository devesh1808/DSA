// Using Recursion

void func(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    func(root->left, ans);
    func(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    func(root, ans);
    return ans;
}

// Using Iteration (2 stack)

vector<int> postorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    stack<TreeNode *> st1;
    stack<int> st2;
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root->val);
        if (root->left)
            st1.push(root->left);
        if (root->right)
            st1.push(root->right);
    }
    while (!st2.empty())
    {
        ans.push_back(st2.top());
        st2.pop();
    }
    return ans;
}