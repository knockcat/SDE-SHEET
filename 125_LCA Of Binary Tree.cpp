// Time Complexity -> O(n)
// Space Complexity -> O(2n) + O(n) auxiliary stack space

bool getPathX(TreeNode<int>* root, int x, vector<int>& pathX)
{
    if(!root)
        return false;
        
    pathX.push_back(root->data);
    
    if(root->data == x)
        return true;
    
    if(getPathX(root->left, x, pathX) or getPathX(root->right, x, pathX))
        return true;

    pathX.pop_back();
    return false;
}

bool getPathY(TreeNode<int>* root, int x, vector<int>& pathY)
{
    if(!root)
        return false;
        
    pathY.push_back(root->data);
    
    if(root->data == x)
        return true;
    
    if(getPathY(root->left, x, pathY) or getPathY(root->right, x, pathY))
        return true;

    pathY.pop_back();
    return false;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here

    TreeNode<int>* node1 = root, *node2 = root;

    vector<int> pathX, pathY;

    getPathX(node1, x, pathX);

    getPathY(node2, y, pathY);

    int ans = root->data;

    // for(auto itr : pathX)
    //     cout<<itr<<' ';
    // cout<<endl;

    // for(auto itr : pathY)
    //     cout<<itr<<' ';
    // cout<<endl;

    for(int i = 0; i < pathX.size() and i < pathY.size(); ++i)
    {
        if(pathX[i] == pathY[i])
            ans = pathX[i];
        else
            break;
    }

    return ans;
    
}

// Time Complexity -> O(n)
// Space Complexity -> O(n) auxiliary stack space

TreeNode<int>* helper(TreeNode<int> *root, int x, int y)
{
	//    Write your code here

    if(!root or root->data == x or root->data == y)
        return root;

    TreeNode<int>* left = helper(root->left, x, y);
    TreeNode<int>* right = helper(root->right, x, y);

    if(!left and !right)
        return nullptr;
    else if(!left)
        return right;
    else if(!right)
        return left;
    
    return root;
}


int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here

    TreeNode<int>* node = helper(root, x, y);
    return node->data;
}
