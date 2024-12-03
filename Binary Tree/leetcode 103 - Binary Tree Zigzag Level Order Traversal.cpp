vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> temp(sz);
        for (int i = 0; i < sz; i++)
        {
            TreeNode *p = q.front();
            q.pop();
            if (cnt % 2 == 0)
                temp[i] = p->val;
            else
                temp[sz - i - 1] = p->val;
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
        ans.push_back(temp);
        cnt++;
    }
    return ans;
}