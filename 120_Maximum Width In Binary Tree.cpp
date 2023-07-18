// Time Complexity -> O(N)
// Space Complexity -> O(N)

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    
    if(!root)
        return 0;
        
    queue<TreeNode<int>*> q;

    int ans = 1;

    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        ans = max(ans, size);

        for(int i = 0; i < size; ++i)
        {
            TreeNode<int>* node = q.front();
            q.pop();

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }

    return ans;
}
