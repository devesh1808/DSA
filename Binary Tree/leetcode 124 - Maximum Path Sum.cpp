int func(TreeNode *root, int &mx)
{
    if (root == NULL)
        return 0;
    int leftSum = max(0, func(root->left, mx));
    int rightSum = max(0, func(root->right, mx));
    mx = max(mx, root->val + leftSum + rightSum);
    return max(leftSum, rightSum) + root->val;
}
int maxPathSum(TreeNode *root)
{
    int mx = INT_MIN;
    func(root, mx);
    return mx;
}