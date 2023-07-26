// Time Complexity -> O(n)
// Space Comlexity -> O(n) recursion stack space

int helper(TreeNode<int>* root , int& k)
{
    if(!root)
        return -1;
    
    int left = helper(root->left, k);

    if(left !=-1)
        return left;
    
    --k;

    if(k == 0)
        return root->data;
    
    return helper(root->right, k);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.

    return helper(root, k);

}
