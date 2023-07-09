/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class Node{
    public:
        Node* child[26] = {nullptr};
        bool isWord = false;
    
    bool containsKey(char ch)
    {
        return child[ch-'a'] !=  nullptr;
    }

    void put(char ch, Node* node)
    {
        child[ch - 'a'] = node;
    }

    Node* get(char ch)
    {
        return child[ch-'a'];
    }

    void setEnd()
    {
        isWord = true;
    }

    bool isEnd()
    {
        return isWord;
    }

};


class Trie {

public:

    /** Initialize your data structure here. */

    Node *root;

    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        Node * temp = root;
        int n = word.size();

        for(int i = 0; i < n; ++i)
        {
            if(!temp->containsKey(word[i]))
                temp->put(word[i], new Node());
            temp = temp->get(word[i]);
        }

        temp->setEnd();

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        Node *temp = root;

        int n = word.size();

        for(int i = 0; i < n; ++i)
        {
            if(!temp->containsKey(word[i]))
                return false;
            temp = temp->get(word[i]);
        }

        return temp->isEnd();

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        int n = prefix.size();

        Node* temp = root;

        for(int i = 0; i < n; ++i)
        {
            if(!temp->containsKey(prefix[i]))
                return false;
            temp = temp->get(prefix[i]);
        }

        return true;
    }
};
