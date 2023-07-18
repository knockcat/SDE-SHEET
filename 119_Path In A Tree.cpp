// Time Complexity -> O(N)
// Space Complexity -> O(height) + recursion stack space

bool helper(TreeNode<int>* root, int x, vector<int>& ans)
{
	if(!root)
		return false;
	
	ans.push_back(root->data);

	if(root->data == x)
		return true;
	
	if(helper(root->left, x, ans) or helper(root->right, x, ans))
		return true;
	
	ans.pop_back();
	return false;
	
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.

	if(!root)
		return {};
	
	vector<int> ans;

	helper(root, x, ans);
 
	return ans;
}
