// Time Complexity -> O(n * 32)
// Space Complexity -> O(n * 32)

#include <bits/stdc++.h> 

class Node 
{
    private:
        Node* links[2] = {nullptr};
    public:

        bool containsKey(int bit)
        {
            return  links[bit] != nullptr;
        }

        void put(int bit, Node* node)
        {
            links[bit] = node;
        }

        Node* get(int bit)
        {
            return links[bit];
        }
};

class BitTrie{
    private:
        Node* root;
    public:
        BitTrie()
        {
            root = new Node();
        }
    
        void insert(int num)
        {
            Node *temp = root;
            
            for(int i = 31; i >= 0; --i)
            {
                int bit = (num >> i) & 1;

                if(!temp->containsKey(bit))
                {
                    temp->put(bit, new Node());
                }
                temp = temp->get(bit);
            }
        }

        int findMax(int num)
        {
            Node* temp = root;

            int maxNum = 0;

            for(int i = 31; i >= 0; --i)
            {
                int bit = (num >> i) & 1;

                if(temp->containsKey(1-bit))
                {
                    maxNum |= (1 << i);
                    temp = temp->get(1-bit);
                }
                else
                    temp = temp->get(bit);
            }

            return maxNum;
        }
        

};

int maximumXor(vector<int> A)
{
    // Write your code here.

    BitTrie *trie = new BitTrie();

    for(auto itr : A)
        trie->insert(itr);

    int maxNum = 0;

    for(auto itr : A)
    {
        maxNum = max(maxNum, trie->findMax(itr));
    }

    return maxNum;

}
