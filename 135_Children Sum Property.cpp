// Time Complexity -> O(N)
// Space Complexity -> O(N)

void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.

    if(!root)
        return;
    int cur = 0;
    if(root->left)
        cur += root->left->data;
    if(root->right)
        cur += root->right->data;
    
    if(cur < root->data)
    {
        if(root->left)
            root->left->data = root->data;
        if(root->right)
            root->right->data = root->data;
    }
    else
    {
        root->data = cur;
    }

    changeTree(root->left);
    changeTree(root->right);

    int curr2 = 0;

    if(root->left)
        curr2 += root->left->data;
    if(root->right)
        curr2 += root->right->data;
    
    if(root->left or root->right)
        root->data = curr2;
    
}  
