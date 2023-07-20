// Time Complexity -> O(n)
// Space Comlexity -> O(n)

bool helper(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2)
{
    if(!root1 and !root2)
        return true;

    if((root1 and !root2) or (root2 and !root1))
        return false;
    
    return root1->data == root2->data && helper(root1->left, root2->right) && helper(root1->right, root2->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 

    return helper(root,root);  
}
