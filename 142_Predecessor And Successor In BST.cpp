// Time Complexity -> O(2n) 
// Space Complexity -> O(n) + O(n) recursion stack space

void helper(BinaryTreeNode<int>* root, vector<int>& inorder)
{
    if(!root)
        return;
    
    helper(root->left, inorder);
    inorder.push_back(root->data);
    helper(root->right, inorder);
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    
    vector<int> inorder;
    
    helper(root, inorder);
    
    int pred = -1, succ = -1;

    int n = inorder.size();

    for(int i = 0; i < n; ++i)
    {
        if(inorder[i] == key)
        {
            if(i > 0 )
                pred = inorder[i-1];
            if(i + 1 < n)
                succ = inorder[i+1];
            break;
        }
    }

    return { pred, succ };
}

// Time Complexity -> O(n) 
// Space Complexity -> O(1)

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    
    int pred = -1, succ = -1;

    while(root->data != key)
    {
        if(key > root->data)
        {
            pred  = root->data;
            root = root->right;
        }
        else
        {
            succ = root->data;
            root = root->left;
        }
    }

    BinaryTreeNode<int>* rightSubtree = root->right;

    while(rightSubtree)
    {
        succ = rightSubtree->data;
        rightSubtree = rightSubtree->left;
    }

    BinaryTreeNode<int>* leftSubtree = root->left;

    while(leftSubtree)
    {
        pred = leftSubtree->data;
        leftSubtree = leftSubtree->right;
    }

    return { pred, succ };
}
