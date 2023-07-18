// Time Comlexity -> O(N)
// Space Complexity -> O(N) recursion stack space

void helper(TreeNode<int>* root, int& maxLevel, int level, vector<int>& ans)
{
    if(root)
    {
        if(level > maxLevel)
        {
            ans.push_back(root->data);
            maxLevel = level;
        }
        helper(root->left,  maxLevel, level + 1, ans);
        helper(root->right, maxLevel, level + 1, ans);
    }
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here

    if(!root)
        return {};

    vector<int> ans; 

    int maxLevel = -1;
    
    helper(root, maxLevel, 0, ans);

    return ans;
}

// Time Comlexity -> O(N)
// Space Complexity -> O(N)

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here

    if(!root)
      return {};
    
    vector<int> ans;

    queue<TreeNode<int>*> q;

    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        for(int i = 0; i < size; ++i)
        {
            TreeNode<int>* cur = q.front();
            q.pop();

            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            
            if(i == 0)
                ans.push_back(cur->data);
        }
    }

    return ans;
}
