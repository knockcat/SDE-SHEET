// Time Complexity -> O(N)
// Space Complexity -> O(N) auxiliary stack space

int helper(BinaryTreeNode<int>* root)
{
    if(!root)
        return true;
    
    int left = helper(root->left);
    int right = helper(root->right);

    if(left == -1 or right == -1)
        return -1;
        
    if(abs(left - right) > 1)
        return -1;
    
    return 1 + max(left,right);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.

    if(helper(root) == -1)
        return false;
    return true;

}
