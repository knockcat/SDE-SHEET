// Time Complexity -> O(n)
// Space Complexity -> O(n)

class NodeValue
{
    public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

NodeValue helper(TreeNode<int>* root)
{
    if(!root)
        return NodeValue(INT_MAX, INT_MIN, 0);

    NodeValue left = helper(root->left);
    NodeValue right = helper(root->right);

    if(left.maxNode < root->data and root->data < right.minNode)
    {
        return NodeValue(min(left.minNode, root->data), max(right.maxNode, root->data), left.maxSize + right.maxSize + 1);
    }

    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.

    return helper(root).maxSize;
    
}
