// Time Complexity -> O(n)
// Space Complexity -> O(n)

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!

    if(!root)
        return {};
    
    vector<int> ans;

    queue<BinaryTreeNode<int>*> q;
    
    q.push(root);

    bool ok = true;

    while(!q.empty())
    {
        int size = q.size();

        vector<int> level;

        for(int i = 0; i < size; ++i)
        {
            BinaryTreeNode<int>* cur = q.front();
            q.pop();

            level.push_back(cur->data);

            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        
       for(int i = 0; i < size; ++i)
       {
           if(ok)
            ans.push_back(level[i]);
           else
            ans.push_back(level[size-i-1]);
       }

       ok ^= 1;

    }

    return ans;
}
