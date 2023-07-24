// Time Complexity -> O(n)
// Space Complextity -> O(n)

// Recursive

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.

    if(!root)
        return false;
    
    if(root->data == x)
        return true;

    else if(root->data < x)
        return searchInBST(root->right, x);
        
    else
        return searchInBST(root->left, x);
}

// Time Complexity -> O(n)
// Space Complextity -> O(n)

// Iterative

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.

    while(root)
    {   
        if(root->data == x)
            return true;
        else if(root->data < x)
            root = root->right;
        else
            root = root->left;
    }

    return false;
}
