void func(TreeNode *root, int &ele, int &cnt, int k)
{
    if (root == NULL || cnt >= k)
        return;
    func(root->left, ele, cnt, k);
    cnt++;
    if (cnt == k)
    {
        ele = root->val;
        return;
    }
    func(root->right, ele, cnt, k);
}
int kthSmallest(TreeNode *root, int k)
{
    int ele = -1, cnt = 0;
    func(root, ele, cnt, k);
    return ele;
}