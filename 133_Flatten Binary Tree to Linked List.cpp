// Time Complexity -> O(n)
// Space Complexity -> O(n) auxiliary stack space

void flatten(TreeNode<int>* root, TreeNode<int>*& prev)
{
    if(!root)
        return;
    
    flatten(root->right, prev);
    flatten(root->left, prev);

    root->right = prev;
    root->left = nullptr;

    prev = root;
}

// reverse PostOrderR
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.

    TreeNode<int>* prev = nullptr;

    flatten(root, prev);

    return root;
}

// Time Complexity -> O(n)
// Space Complexity -> O(n) 

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.

    stack<TreeNode<int>*> st;

    if(!root)
        return root;
    
    st.push(root);

    while(!st.empty())
    {
        TreeNode<int>* prev = st.top();

        st.pop();

        if(prev->right)
            st.push(prev->right);
        if(prev->left)
            st.push(prev->left);

        if(!st.empty())
        {
            prev->right = st.top();
        }
    }

    return root;
    
}

// Time Complexity -> O(2n)
// Space Complexity -> O(1) 

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.

    TreeNode<int>* curr = root;

    while(curr)
    {
        if(curr->left)
        {
            TreeNode<int>* prev = curr->left;

            while(prev->right)
                prev = prev->right;
            
            prev->right = curr->right;

            curr->right = curr->left;

            curr->left = nullptr;
        }

        curr = curr->right;
    }
    
    return root;
}
