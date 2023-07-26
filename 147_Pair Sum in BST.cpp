// Time Complexity -> O(n)
// Space Complexity -> O(n)

bool helper(BinaryTreeNode<int>* root,unordered_map<int,int>& mp, int k)
{
    if(!root)
        return false;
    
    if(helper(root->left, mp, k))
        return true;

    if(mp.find(k - root->data) != mp.end())
        return true;
        
    ++mp[root->data];

    return helper(root->right, mp, k);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here

    unordered_map<int,int> mp;

    return helper(root, mp, k);

}
