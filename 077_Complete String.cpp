#include <bits/stdc++.h> 

class Node{
    public:
      Node *child[26] = {nullptr};
      bool isWord = false;

      bool containsKey(char ch) { return child[ch - 'a'] != nullptr; }

      void put(char ch, Node *node) { child[ch - 'a'] = node; }

      Node *get(char ch) { return child[ch - 'a']; }

      void setEnd() { isWord = true; }

      bool isEnd() { return isWord; }

};

class Trie
{
    private:
        Node* root;

    public:
        Trie()
        {
            root = new Node;
        }

        void insert(string& word)
        {
            Node* temp = root;

            int n = word.size();

            for(int i = 0; i < n; ++i)
            {
                if(!temp->containsKey(word[i]))
                    temp->put(word[i], new Node());
                temp = temp->get(word[i]);
            }
            temp->setEnd();
        }

        bool checkAllPrefixes(string& word)
        {
            Node* temp = root;

            bool ok = true;

            int n = word.size();

            for(int i = 0; i < n; ++i)
            {
                if(temp->containsKey(word[i]))
                {
                    temp = temp->get(word[i]);
                    ok &= temp->isEnd();
                }
                else
                    return false;
            }

            return ok;
        }
};

string completeString(int n, vector<string> &a){
    // Write your code here.

    Trie *obj = new Trie();

    for(auto itr : a)
        obj->insert(itr);
    
    string ans;
    
    for(auto itr : a)
    {
        if(obj->checkAllPrefixes(itr))
        {
            if(ans.size() < itr.size())
                ans = itr;
            else if(itr.size() == ans.size() and itr < ans)
                ans = itr;
        }
    }

    if(!ans.empty())
        return ans;
    return "None";
    
}
