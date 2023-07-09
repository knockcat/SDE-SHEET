#include <bits/stdc++.h> 

class Node
{
    public:
        Node* child[26] = {nullptr};
        bool isWord;
        int cntEndWith;
        int cntPrefix;
    
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
        return child[ch-'a'];
    }

    void setEnd()
    {
        isWord = true;
    }

    void remEnd()
    {
        isWord = false;
    }

    bool isEnd()
    {
        return isWord;
    }

    void increaseEnd()
    {
        ++cntEndWith;
    }

    void increasePrefix()
    {
        ++cntPrefix;
    }

    void reduceEnd()
    {
        --cntEndWith;
    }

    void reducePrefix()
    {
        --cntPrefix;
    }

    int getPrefix()
    {
        return cntPrefix;
    }

    int getEnd()
    {
        return cntEndWith;
    }
};

class Trie{

    public:

    Node* root;

    Trie(){
        // Write your code here.

        root = new Node;
    }

    void insert(string &word){
        // Write your code here.

        Node* temp = root;
        int n = word.size();

        for(int i = 0; i < n; ++i)
        {
            if(!temp->containsKey(word[i]))
                temp->put(word[i], new Node());
            temp = temp->get(word[i]);
            temp->increasePrefix();
        }

        temp->setEnd();
        temp->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.

        Node* temp = root;  
        int n = word.size();

        for(int i = 0; i < n; ++i)
        {
            if(temp->containsKey(word[i]))
                temp = temp->get(word[i]);
            else
                return 0;
        }

        return temp->getEnd();

    }

    int countWordsStartingWith(string &word){
        // Write your code here.

        Node* temp = root;
        int n = word.size();

        for(int i = 0; i < n;  ++i)
        {
            if(temp->containsKey(word[i]))
                temp = temp->get(word[i]);
            else
                return 0;
        }

        return temp->getPrefix();
    }

    void erase(string &word){
        // Write your code here.

        Node* temp = root;
        int n = word.size();

        for(int i = 0; i < n; ++i)
        {
            if(temp->containsKey(word[i]))
            {
                temp = temp->get(word[i]);
                temp->reducePrefix();
            }
            else
                return;
        }

        temp->reduceEnd();

        if(temp->getEnd() == 0)
            temp->remEnd();
    }
};
