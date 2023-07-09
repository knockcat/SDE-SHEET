// Time Complexity -> O(n^3)
// Space Complexity -> O(n^2)

#include <bits/stdc++.h> 
int distinctSubstring(string &word) {
    //  Write your code here.

    int n = word.size();
    set<string> st;

    for(int i = 0; i < n; ++i)
    {
        string cur = "";
        for(int j = i; j < n; ++j)
        {
            cur += word[j];
            st.insert(cur);
        }
    }

    return st.size();
}


#include <bits/stdc++.h> 

class Node{
    private:
        Node* child[26] = {nullptr};
    
    public:
        bool containsKey(char ch)
        {
            return child[ch - 'a'] != nullptr;
        }

        void put(char ch, Node* node)
        {
            child[ch - 'a'] = node;
        }

        Node* get(char ch)
        {
            return child[ch - 'a'];
        }
    
};

// Time Complexity -> O(n^2)
// Space Complexity -> O(n^2)

int distinctSubstring(string &word) {
    //  Write your code here.

    int n = word.size();
    
    Node* root = new Node();

    int cnt = 0;

    for(int i = 0; i < n; ++i)
    {
        Node *temp = root;
        for(int j = i; j < n; ++j)
        {
            if(!temp->containsKey(word[j]))
            {
                ++cnt;
                temp->put(word[j], new Node());
            }

            temp = temp->get(word[j]);
        }
    }

    return cnt;
}
