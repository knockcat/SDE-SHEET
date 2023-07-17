// Recursive

// Time Complexity ->  O(N)
// Space Complexity ->  O(N) Auxiliary Stack Space

void inorder(TreeNode* root, vector<int>& ans)
{
    if(!root)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.

    vector<int> ans;

    inorder(root, ans);

    return ans;
}

// Iterative

// Time Complexity ->  O(N)
// Space Complexity ->  O(N) 

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.

    stack<TreeNode*> st;

    TreeNode*node = root;

    vector<int> inorder;

    while(true)
    {
        if(node)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }

    return inorder;
    
}


// Iterative

// Time Complexity ->  O(2N) ~ O(N)
// Space Complexity ->  O(1) 

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    
    vector<int> inorder;

    TreeNode* curr = root;
    
    while(curr)
    {
        if(!curr->left)
        {
            inorder.push_back(curr->data);
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
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return inorder;
}
