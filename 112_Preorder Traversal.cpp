// Recursive

// Time Complexity -> O(N)
// Space Complexity -> O(N) Auxiliary Stack Space

void helper(TreeNode* root, vector<int>& preorder)
{
    if(root)
    {
        preorder.push_back(root->data);
        helper(root->left, preorder);
        helper(root->right, preorder);
    }
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.

    vector<int> preorder;

    helper(root, preorder);

    return preorder;
}

// Iterative

// Time Complexity -> O(N)
// Space Complexity -> O(N)

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    
    vector<int> preorder;

    if(!root)
        return preorder;

    stack<TreeNode*> st;

    st.push(root);

    while(!st.empty())
    {
        TreeNode* node = st.top();
        
        preorder.push_back(node->data);

        st.pop();
                
        if(node->right)
            st.push(node->right);
            
        if(node->left)
            st.push(node->left);
    }

    return preorder;
}

// Morris Traversal

// Time Complexity -> O(N)
// Space Complexity -> O(2N) ~ O(N)

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
     if(!root)
        return {};
    
    vector<int> preorder;

    TreeNode* curr = root;

    while(curr)
    {
        if(!curr->left)
        {
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            TreeNode* prev = curr->left;
            
            while(prev->right and prev->right != curr)
                prev = prev->right;
            
            if(prev->right == nullptr)
            {
                prev->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }
            else{
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }

    return preorder;
}
