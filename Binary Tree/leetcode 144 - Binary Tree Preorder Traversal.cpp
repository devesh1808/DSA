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