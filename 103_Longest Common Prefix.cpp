// Time Complexity -> O(n*m) n is the size of arr and m is the length of string 
// Space Complexity -> O(1) 

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here

    string ans; 

    for(int i = 0; i < arr[0].size(); ++i)
    {
        bool ok = true;
        for(int j = 1; j < n; ++j)
        {  
            if(arr[j].size() < i or arr[j][i] != arr[0][i])
            {
                ok = false;
                break;
            }
        }
        if(ok)
            ans += arr[0][i];
        else
            break;
    }

    return ans;
   
}

// Trie

// Time Complexity -> O(n*m) n is the size of arr and m is the length of string 
// Space Complexity -> O(n*m) 

class Node{
  
    private:
      Node *child[26] = {nullptr};
      bool isWord = false;
      int cntPrefix = 0;
    
    public:
        
        bool containsKey(char ch)
        {
            return child[ch-'a'] != nullptr;
        }

        void put(char ch, Node* node)
        {
            child[ch-'a'] = node;
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

        void increasePrefix()
        {
            ++cntPrefix;
        }

        int getPrefix(){
            return cntPrefix;
        }
};

class Trie{
  
    private:
        Node *root;
    public:
        Trie()
        {
            root = new Node();
        }  

        void insert(string& word)
        {
            int n = word.size();

            Node* temp = root;

            for(int i = 0; i < n; ++i)
            {
                if(!temp->containsKey(word[i]))
                    temp->put(word[i], new Node());
                temp = temp->get(word[i]);
                temp->increasePrefix();
            }
            temp->setEnd();
        }
        
        string search(string& word, int n)
        {
            int size = word.size();

            string ans;

            Node* temp = root;

            for(int i = 0; i < size; ++i)
            {
                if(!temp->containsKey(word[i]))
                    break;
                    
                temp = temp->get(word[i]);
                
                if(temp->getPrefix() == n)
                    ans += word[i];
                else
                    break;
            }
            return ans;
        }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here

    Trie *trie = new Trie();

    for(auto itr : arr)
        trie->insert(itr);
    
    return trie->search(arr[0], n);
}

