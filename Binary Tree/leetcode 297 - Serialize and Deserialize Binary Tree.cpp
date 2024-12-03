void levelOrder(TreeNode *root, string &s)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    string root_val = to_string(root->val);
    s.append(root_val);
    while (q.size())
    {
        TreeNode *front = q.front();
        q.pop();
        if (front)
        {
            q.push(front->left);
            q.push(front->right);
            if (front->left)
            {
                string val = to_string(front->left->val);
                s.push_back(',');
                s.append(val);
            }
            else
            {
                s.push_back(',');
                s.push_back('#');
            }
            if (front->right)
            {
                string val = to_string(front->right->val);
                s.push_back(',');
                s.append(val);
            }
            else
            {
                s.push_back(',');
                s.push_back('#');
            }
        }
    }
}

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    string s;
    levelOrder(root, s);
    return s;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data.length() == 0)
    {
        return NULL;
    }
    string s1 = "";
    int i = 0;
    int n = data.length();
    while (i < n && data[i] != ',')
    {
        s1.push_back(data[i]);
        i++;
    }
    i++;
    int x = stoi(s1);
    TreeNode *root = new TreeNode(x);
    s1.erase();
    queue<TreeNode *> q;
    q.push(root);
    while (q.size())
    {
        TreeNode *front = q.front();
        q.pop();
        while (i < n && data[i] != ',')
        {
            s1.push_back(data[i]);
            i++;
        }
        i++;
        if (s1 == "#")
        {
            front->left = NULL;
        }
        else
        {
            int val = stoi(s1);
            TreeNode *left = new TreeNode(val);
            front->left = left;
            q.push(left);
        }
        s1.erase();
        while (i < n && data[i] != ',')
        {
            s1.push_back(data[i]);
            i++;
        }
        i++;
        if (s1 == "#")
        {
            front->right = NULL;
        }
        else
        {
            int val = stoi(s1);
            TreeNode *right = new TreeNode(val);
            front->right = right;
            q.push(right);
        }
        s1.erase();
    }
    return root;
}