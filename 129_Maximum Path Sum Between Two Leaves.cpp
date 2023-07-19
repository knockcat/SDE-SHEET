// Time Complexity -> O(n)
// Space Complexity -> O(n)

long long int helper(TreeNode<int>* root, long long int& ans)
{
    if(!root)
        return 0;

    long long int left = max(0ll, helper(root->left, ans));

    long long int right = max(0ll, helper(root->right, ans));

    ans = max(ans, left + right + root->val);

    return root->val + max(left, right);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.

    if(!root or !root->left or !root->right)
        return -1;

    long long int ans = INT_MIN;

    helper(root, ans);

    return ans;
}
