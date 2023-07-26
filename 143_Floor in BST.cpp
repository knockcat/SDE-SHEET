// Time Complexity -> O(n)
// Space Complexity -> O(1)

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.

    int ans = -1;

    while(root)
    {
        if(root->val <= X)
        {
            ans = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return ans;
}
