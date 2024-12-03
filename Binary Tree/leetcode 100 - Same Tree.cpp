bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL || q == NULL)
        return p == q;
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    return left && right && (p->val == q->val);
}