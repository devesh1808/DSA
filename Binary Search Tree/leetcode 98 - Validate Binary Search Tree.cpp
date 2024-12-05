bool func(TreeNode *root, long mn, long mx)
{
    if (root == NULL)
        return true;
    if (root->val <= mn || root->val >= mx)
        return false;
    return func(root->left, mn, root->val) && func(root->right, root->val, mx);
}
bool isValidBST(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    long mn = LONG_MIN, mx = LONG_MAX;
    return func(root, mn, mx);
}