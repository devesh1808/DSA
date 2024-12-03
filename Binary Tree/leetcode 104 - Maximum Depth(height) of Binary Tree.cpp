// recursive solution

int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}

// iterative solution

int maxDepth(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;

    while (!q.empty())
    {
        depth++;
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
    }

    return depth;
}