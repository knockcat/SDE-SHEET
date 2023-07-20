// Time Complexity ->  O(n)
// Space Complexity -> O(n)

TreeNode<int>* helper(int inStart, int inEnd, int preStart, int preEnd, vector<int>& inorder, vector<int>& preorder, unordered_map<int,int>& mp)
{
    if(inStart > inEnd or preStart > preEnd)
        return nullptr;
    
    TreeNode<int>* root = new TreeNode<int>(preorder[preStart]);

    int rootIdx = mp[root->data];
    int numsLeft = rootIdx - inStart;

    root->left = helper(inStart, rootIdx-1, preStart + 1, preStart + numsLeft, inorder, preorder, mp);
    root->right = helper(rootIdx + 1, inEnd, preStart + numsLeft + 1, preEnd, inorder, preorder, mp);

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here

    unordered_map<int,int> mp;

    for(int i = 0; i < preorder.size(); ++i)
        mp[inorder[i]] = i;
    
    TreeNode<int>* root = helper(0, inorder.size()-1, 0, preorder.size()-1, inorder, preorder, mp);

    return root;
}
