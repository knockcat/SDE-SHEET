// BFS

// // Time COmplexity -> O(n log(n))
// // Space Complexity -> O(N) queue + O(N) ans vector

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.

    if(!root)
        return {};

    map<int,int> mp;

    queue<pair<TreeNode<int>*, int> > q;

    vector<int> ans;
    
    q.push({root, 0});

    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();

        TreeNode<int>* node = curr.first;
        int vertical = curr.second;

        if(mp.find(vertical) == mp.end())
            mp[vertical] = node->val;
        
        if(node->left)
            q.push({node->left, vertical - 1});

        if(node->right)
            q.push({node->right, vertical + 1});
    }

    for(auto itr : mp)
        ans.push_back(itr.second);
    
    return ans;
}

// DFS

// // Time COmplexity -> O(n log(n))
// // Space Complexity -> O(N) recursion stack space + O(N) ans vector

void helper(TreeNode<int>* root, int level, int vertical, map<int,pair<int,int>>& mp)
{
    if(root)
    {
        if(mp.find(vertical) != mp.end())
        {
            auto cur = mp[vertical];
            int prev = cur.first;

            if(prev > level)
            {
                mp.erase(vertical);
                mp.insert({vertical,{level, root->val}});
            }
        }
        else
            mp.insert({vertical,{level, root->val}});
    }

    if(root->left)
        helper(root->left, level+1, vertical-1, mp);
    if(root->right)
        helper(root->right, level+1, vertical+1, mp);
}

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.

    if(!root)
        return {};

    map<int,pair<int,int>> mp;

    vector<int> ans;
    
    helper(root, 0, 0, mp);

    for(auto itr : mp)
        ans.push_back(itr.second.second);
    
    return ans;
}
