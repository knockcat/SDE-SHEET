// Time Complexity -> O(n)
// Space Complexity -> O(n)

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
       string str;

       queue<TreeNode<int>* > q;

       q.push(root);

       while(!q.empty())
       {
           int size = q.size();

           for(int i = 0; i < size; ++i)
           {
               TreeNode<int>* curr = q.front();
                q.pop();

                if(!curr)
                {
                    str += "-1 ";
                    continue;
                }

                q.push(curr->left); 

                q.push(curr->right);
               
                str += to_string(curr->data) + ' ';
           }
       }

       return str;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    
    int n = serialized.size();

    vector<int> v;

    string cur = "";
    for(int i = 0; i < n; ++i)
    {
        if(serialized[i] == ' ')
        {
            if(!cur.empty())
            {
                v.push_back(stoi(cur));
                cur.clear();
            }
        }
        else
            cur += serialized[i];
    }

    if(!cur.empty())
        v.push_back(stoi(cur));

    int ptr = 0;

    queue<TreeNode<int>*> q;

    if(v[ptr] == -1)
        return nullptr;

    TreeNode<int>* root = new TreeNode<int>(v[ptr++]);

    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        for(int i = 0; i < size; ++i)
        {
            TreeNode<int>* cur = q.front();
            q.pop();

            if(v[ptr] != -1)
            {
                cur->left = new TreeNode<int>(v[ptr]);
                q.push(cur->left);
            }
            else
                cur->left = nullptr;
            
            ++ptr;

            if(v[ptr] != -1)
            {
                cur->right = new TreeNode<int>(v[ptr]);
                q.push(cur->right);
            }
            else
                cur->right = nullptr;
            
            ++ptr;
        }
    }

    return root;
}



