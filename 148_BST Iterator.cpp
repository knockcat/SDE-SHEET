// Time Complexity -> O(n)
// Space Complexity -> O(n)

class BSTiterator
{
    public:
        stack<TreeNode<int>*> st;

        void pushAll(TreeNode<int>* root)
        {
            while(root != nullptr)
            {
                st.push(root);
                root = root->left;
            }
        }

        BSTiterator(TreeNode<int> *root)
        {
            // write your code here
            pushAll(root);
        }

        int next()
        {
            // write your code here

            if(st.empty())
                return -1;

            TreeNode<int>* curr = st.top();

            st.pop();

            pushAll(curr->right);

            return curr->data;

        }

        bool hasNext()
        {
            // write your code here
            return !st.empty();
        }
};
