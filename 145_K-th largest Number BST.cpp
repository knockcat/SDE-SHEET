// Time Complexity -> O(n)
// Space Complexity -> O(n)

void helper(TreeNode<int>* root, vector<int>& inorder)
{
    if(!root)
        return ;
    
    helper(root->left, inorder);
    inorder.push_back(root->data);
    helper(root->right, inorder);

}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.

    vector<int> inorder;

    helper(root , inorder);

    if(inorder.size() >= k)
        return inorder[inorder.size()-k];
    
    return -1;
}

// Time Complexity -> O(n)
// Space Complexity -> O(n)

int helper(TreeNode<int>* root, int& k)
{
    if(root == nullptr)
        return -1;
    
    int right = helper(root->right, k);
    
    if(right != -1)
        return right;
    
    --k;

    if(k == 0)
        return root->data;
    
    return helper(root->left, k);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.

    return helper(root, k);
}
