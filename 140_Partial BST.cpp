// Time Complexity -> O(n)
// Space Complexity -> O(n)

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here

    if(!root)
        return true;
    
    bool left1 = true, right1 = true;

    left1 = validateBST(root->left);
    
    right1 = validateBST(root->right);

    if(left1 and right1)
    {
        bool one = true , two = true;

        if(root->left)
        {
            one = root->left->data <= root->data;
        }
        if(root->right)
        {
            two= root->right->data >= root->data;
        }

        return one & two;
    }

    return false;    
}

// Time Complexity -> O(n)
// Space Complexity -> O(n)

bool helper(BinaryTreeNode<int>* root, int maxi, int mini)
{
    if(!root)
        return true;
    
    if(maxi < root->data or mini > root->data)
        return false;
    
    bool left = helper(root->left, root->data, mini);

    bool right = helper(root->right, maxi, root->data);

    return left & right;
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here

    return helper(root,INT_MAX,INT_MIN);
}

// Time Complexity -> O(n)
// Space Complexity -> O(n)

bool helper(BinaryTreeNode<int>* root, BinaryTreeNode<int>*& prev)
{
   if(!root)
    return true;

    if(!helper(root->left, prev))
        return false;
    
    if(prev and root->data < prev->data)
        return false;
    
    prev = root;

    return helper(root->right, prev);
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here

    BinaryTreeNode<int>* prev = nullptr;
    return helper(root,prev);
}
