// Time Complexity -> O(n)
// Space Complexity -> O(n)

bool isLeaf(TreeNode<int>* root)
{
    return (!root->left and !root->right);
}

void leftBoundary(TreeNode<int>* root, vector<int>& ans)
{
    TreeNode<int>* node = root->left;

    while(node)
    {
        if(!isLeaf(node))
            ans.push_back(node->data);
        if(node->left)
            node = node->left;
        else
            node = node->right;
    }
}

void leaves(TreeNode<int>* root, vector<int>& ans)
{
    if(isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }

    if(root->left)
        leaves(root->left,ans);
    if(root->right)
        leaves(root->right, ans);
}

void rightBoundary(TreeNode<int>* root, vector<int>& ans)
{
    TreeNode<int>* node = root->right;

    vector<int> right;

    while(node)
    {
        if(!isLeaf(node))
            right.push_back(node->data);
        if(node->right)
            node = node->right;
        else
            node = node->left;
    }

    for(int i = right.size()-1; i >= 0; --i)
        ans.push_back(right[i]);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.

    if(!root)
        return {};

    vector<int> ans;
    
    if(!isLeaf(root))
        ans.push_back(root->data);
    
    leftBoundary(root, ans);
    leaves(root, ans);
    rightBoundary(root, ans);

    return ans;


}
