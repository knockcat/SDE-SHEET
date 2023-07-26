// Time Complexity -> O(N)
// Space Complexity -> O(N)

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here

    if(!root)
        return nullptr;

    if(root->data < P->data and root->data < Q->data)
        return LCAinaBST(root->right, P, Q);
    
    if(root->data > P->data and root->data > Q->data)
        return LCAinaBST(root->left, P, Q);
    
    return root;
}
