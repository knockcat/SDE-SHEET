// Time Complexity -> O(n)
// Space Complexity -> O(n) Auxiliary Stack Space

bool helper(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2)
{
    if(!root1 and !root2)
        return true;
    if(root1 and !root2 or root2 and !root1)
        return false;

    if(root1->data != root2->data)
        return false;
    
    if(!helper(root1->left, root2->left) or !helper(root1->right, root2->right))
        return false;
    
    return true;
}

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here.

    return helper(root1, root2); 	 
}
