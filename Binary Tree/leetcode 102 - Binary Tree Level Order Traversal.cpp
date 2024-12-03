vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> temp;
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *p = q.front();
            q.pop();
            temp.push_back(p->val);
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
        ans.push_back(temp);
    }
    return ans;