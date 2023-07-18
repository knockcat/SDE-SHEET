// Time Complexity -> O(3N) ~ O(N)
// Space Complexity -> O(3N) ~ O(N)

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.

    vector<vector<int>> ans;

    if(!root)
        return ans;

    vector<int> inorder, preorder, postorder;

    stack<pair<BinaryTreeNode<int>*,int>> st;

    st.push({root, 1});

    while(!st.empty())
    {
        auto cur = st.top();
        BinaryTreeNode<int>* node = cur.first;
        int cnt = cur.second;

        st.pop();

        if(cnt == 1)
        {
            preorder.push_back(node->data);
            st.push({node, cnt+1});

            if(node->left)
            {
                st.push({node->left, 1});
            }
        }
        else if(cnt == 2)
        {
            inorder.push_back(node->data);
            st.push({node, cnt+1});

            if(node->right)
            {
                st.push({node->right,1});
            }
        }
        else
        {
            postorder.push_back(node->data);
        }
    }

    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);

    return ans;
}
