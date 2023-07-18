// Recursive

// Time Complexity -> O(n(log n))
// Space Complexity -> O(N) + O(N) ~ O(N)

void helper(TreeNode<int>* root, int vertical,int level, map<int, map<int,vector<int>>>& mp)
{
    if(root)
    {
        mp[vertical][level].push_back(root->data);

        if(root->left)
            helper(root->left,  vertical - 1, level + 1, mp);

        if(root->right)
            helper(root->right, vertical + 1, level + 1, mp);
    }
}

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.

    // vertical, level , list

    if(!root)
        return {};

    map<int, map<int, vector<int>>> mp;

    helper(root, 0, 0, mp);

    vector<int> ans;

    for(auto x : mp)
    {
        for(auto itr : x.second)
        {
            for(auto val : itr.second)
                ans.push_back(val);
        }
    }

    return ans;

}


// Level Order Traversal

// Time Complexity -> O(n(log n))
// Space Complexity -> O(N) + O(N) ~ O(N)

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.

    // vertical, level , list

    if(!root)
        return {};

    queue<pair<TreeNode<int>*,int>> q;

    map<int, vector<int>> mp;

    q.push({root,0});

    while(!q.empty())
    {
        auto cur = q.front();

        q.pop();

        TreeNode<int>* node = cur.first;
        int vertical = cur.second;

        mp[vertical].push_back(node->data);

        if(node->left)
            q.push({node->left,vertical-1});

        if(node->right)
            q.push({node->right,vertical+1});
    }

    vector<int> ans;

    for(auto x : mp)
    {
        for(auto itr : x.second)
        {
            ans.push_back(itr);
        }
    }

    return ans;

}
