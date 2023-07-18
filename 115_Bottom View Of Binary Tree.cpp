// BFS

// Time Complexity -> O(n log(n))
// Space Complexity -> O(n) queue + O(N) ans vector ~ O(N)

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.

    if(!root)
        return {};

    vector<int> ans;

    map<int,int> mp;

    queue<pair<BinaryTreeNode<int>*, int>> q;

    q.push({root, 0});

    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();

        BinaryTreeNode<int>* node = curr.first;
        int vertical = curr.second;

        mp[vertical] = node->data;

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

// Time Complexity -> O(n log(n))
// Space Complexity -> O(n) // recursion stack space O(N) ans vector

void helper(BinaryTreeNode<int>* root, int level, int vertical, map<int,pair<int,int>>& mp)
{
    
    if(root)
    {
        if(mp.find(vertical) != mp.end())
        {
            auto prev = mp[vertical];

            if(prev.first < level)
            {
                mp.erase(vertical);
                mp.insert({vertical,{level, root->data}});
            }
            if(prev.first == level)
                mp[vertical].second = root->data;
        }
        else
            mp.insert({vertical,{level, root->data}});

        if(root->left)
            helper(root->left, level + 1, vertical - 1, mp);
        if(root->right)
            helper(root->right, level + 1, vertical + 1, mp);
    }
}

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.

    if(!root)
        return {};

    vector<int> ans;

    map<int,pair<int,int>> mp;

    helper(root, 0, 0, mp);

    for(auto itr : mp)
        ans.push_back(itr.second.second);

    return ans; 
}
