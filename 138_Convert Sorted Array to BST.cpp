// Time Complexity -> O(n)
// Space Complexity -> O(log n)

TreeNode<int>* bst(int start, int end, vector<int>& arr)
{
    if(start > end)
        return nullptr;
    
    int mid = (start + end) >> 1;

    TreeNode<int>* node = new TreeNode<int>(arr[mid]);

    node->left = bst(start, mid - 1, arr);

    node->right = bst(mid + 1, end, arr);

    return node;
}


TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.

    if(n == 0)
        return nullptr;
    
    return bst(0, n-1, arr);
}
