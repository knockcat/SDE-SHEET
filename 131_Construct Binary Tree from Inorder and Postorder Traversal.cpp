// Time Complexity -> O(n)
// Space Complexity -> O(n)

TreeNode<int>* helper(int inStart, int inEnd, int postStart, int postEnd, vector<int>& postOrder, vector<int>& inOrder, unordered_map<int,int>& mp)
{
     if(inStart > inEnd or postStart > postEnd)
          return nullptr;
     
     TreeNode<int>* root = new TreeNode<int>(postOrder[postEnd]);

     int rootIdx = mp[root->data];

     int numsLeft = rootIdx - inStart;

     root->left = helper(inStart, rootIdx - 1, postStart, postStart + numsLeft - 1, postOrder, inOrder, mp);
     root->right = helper(rootIdx+1, inEnd, postStart + numsLeft, postEnd-1, postOrder, inOrder, mp);

     return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.

     unordered_map<int, int> mp;

     for(int i = 0; i < postOrder.size(); ++i)
          mp[inOrder[i]] = i;

     TreeNode<int>* root = helper(0, inOrder.size()-1, 0, postOrder.size()-1, postOrder, inOrder, mp);

     return root;

}
