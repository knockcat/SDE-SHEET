// Time Complexity ->  O(n)
// Space Complexity -> O(1)

TreeNode<int>* helper(int& i, int upper_bound, vector<int>& preOrder)
{
    if(i == preOrder.size() or preOrder[i] > upper_bound)
        return nullptr;
    
    TreeNode<int>* root = new TreeNode<int>(preOrder[i++]);

    root->left = helper(i, root->data, preOrder);
    
    root->right = helper(i, upper_bound, preOrder);

    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.

    int i = 0, upper_bound = INT_MAX;

    return helper(i, upper_bound, preOrder);
    
}

// Time Complexity ->  O(n)
// Space Complexity -> O(n)

TreeNode<int>* helper(int inStart, int inEnd, int preStart, int preEnd, vector<int>& preOrder, vector<int>& inOrder, unordered_map<int,int>& mp)
{
    if(inStart > inEnd or preStart > preEnd)
        return nullptr;
    
    TreeNode<int>* node = new TreeNode<int>(preOrder[preStart]);

    int idx = mp[node->data];
    
    int numsLeft = idx - inStart;

    node->left =  helper(inStart, idx-1, preStart+1, preStart + numsLeft, preOrder,  inOrder, mp);
    
    node->right = helper(idx+1, inEnd, preStart+numsLeft+1, preEnd, preOrder, inOrder, mp);
    
    return node;
    
}


TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.

    vector<int> inOrder = preOrder;

    sort(inOrder.begin(), inOrder.end());

    int n = preOrder.size();
    
    int instart = 0, inEnd = n-1, preStart = 0, preEnd = n-1;

    unordered_map<int,int> mp;

    for(int i = 0; i < n; ++i)
        mp[inOrder[i]] = i;

   TreeNode<int>* root = helper(instart, inEnd, preStart, preEnd, preOrder, inOrder, mp);

   return root;
    
}

// Time Complexity ->  O(n log n)
// Space Complexity -> O(n)

TreeNode<int>* bst(int start, int end, vector<int>& inorder)
{
    if(start > end)
        return nullptr;
    
    int mid = (start + end) >> 1;

    TreeNode<int>* node = new TreeNode<int>(inorder[mid]);

    node->left = bst(start, mid-1, inorder);

    node->right = bst(mid+1, end, inorder);

    return node;
}


TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.

    vector<int> inorder = preOrder;

    sort(inorder.begin(), inorder.end());

    int n = preOrder.size();

    return bst(0, n-1, inorder);

}
