// Recursive

// Time Complexity -> O(N)
// Space Complexity -> O(N) Auxiliary Stack Space

void helper(TreeNode* root, vector<int>& postorder)
{
    if(root)
    {
        helper(root->left, postorder);
        helper(root->right, postorder);
        postorder.push_back(root->data);
    }
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.

    vector<int> postorder;

    helper(root, postorder);

    return postorder;
}

// Iterative 2 Stack

// Time Complexity -> O(N)
// Space Complexity -> O(2N) 

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    
    vector<int> postorder;

    if(!root)
        return postorder;
    
    stack<TreeNode*> st1;
    stack<int> st2;

    st1.push(root);

    while(!st1.empty())
    {
        TreeNode* node = st1.top();
        
        st1.pop();

        st2.push(node->data);

        if(node->left)
        {
            st1.push(node->left);
        }
        if(node->right)
        {
            st1.push(node->right);
        }
    }

    while(!st2.empty())
    {
        postorder.push_back(st2.top());
        st2.pop();
    }

    return postorder;
}

// Iterative 1 Stack

// Time Complexity -> O(N)
// Space Complexity -> O(N) 

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.

    stack<TreeNode*> st;

    vector<int> posorder;

    TreeNode* curr = root;

    while(curr or !st.empty()){
        
        if(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            TreeNode* temp = st.top()->right;
            if(temp == nullptr)
            {
                temp = st.top();
                st.pop();
                posorder.push_back(temp->data);
                
                while(!st.empty() and st.top()->right == temp)
                {
                    temp = st.top();
                    st.pop();
                    posorder.push_back(temp->data);
                }
            }   
            else
                curr = temp;
        }
        
    }

    return posorder;
}

// Morris Traversal

// Time Complexity -> O(2N) ~ O(N)
// Space Complexity -> O(1) 

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.

    vector<int> postorder;

    if(!root)
        return postorder;

    TreeNode* curr = root;

    while(curr)
    {
        if(!curr->right)
        {
            postorder.push_back(curr->data);
            curr = curr->left;
        }
        else
        {
            TreeNode* prev = curr->right;
            
            while(prev->left and prev->left != curr)
                prev = prev->left;
            
            if(prev->left == nullptr)
            {
                prev->left = curr;
                postorder.push_back(curr->data);
                curr = curr->right;
            } 
            else
            {
                prev->left = nullptr;
                curr = curr->left;    
            }
        }
    }

    reverse(postorder.begin(),postorder.end());
    
    return postorder;
}
