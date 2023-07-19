// Time Complexity -> O(N)
// Space Complexity -> O(N)

int helper(TreeNode<int>* root, int& diameter)
{
    if(!root)
        return 0;
    
    int left = helper(root->left, diameter);
    int right = helper(root->right,diameter);

    diameter = max(diameter, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.

    int diameter = 0;

    helper(root, diameter);

    return diameter;
}
