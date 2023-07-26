// Time Complexity -> O(n)
// Space Complexity -> O(1)

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.

    int ans = -1;

    while(node)
    {
        if(node->data < x)
            node = node->right;
        else
        {
            ans = node->data;
            node = node->left;
        }
    }

    return ans;
}
