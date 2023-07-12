// Time Complexity -> O(Q * capacity)
// Space Complxity -> O(capacity)

// Q is number of queries

#include<bits/stdc++.h>

class LRUCache
{
public:

    vector<pair<int,int>> v;
    int cap, size;
    
    LRUCache(int capacity)
    {
        // Write your code here
        size = capacity;
        cap = 0;
    }

    int get(int key)
    {
        // Write your code here

        for(int i = 0; i < v.size(); ++i)
        {
            if(v[i].first == key)
            {
                int val = v[i].second;

                v.erase(v.begin() + i);

                v.insert(v.begin(), {key, val});

                return val;
            }    
        }

        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here

        bool ok = false;
        
        for (int i = 0; i < v.size(); ++i)
            {
                if(v[i].first == key)
                {
                    v.erase(v.begin() + i);
                    v.insert(v.begin(), {key, value});
                    ok = true;
                    return;
                }
        }
        if(cap < size)
        {
            ++cap;
        }
        else
        {
            v.pop_back();
        }
        if(!ok)
             v.insert(v.begin(),{key, value});
    }
};

// Time Complexity -> O(Q)
// Space Complxity -> O(capacity)


#include<bits/stdc++.h>

class Node{

    public:

        int data;
        Node *prev ,*next;
        int key, value;

        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
};

class LRUCache
{
public:
    
    int cap;

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mp;

    void addNode(Node* ptr)
    {
        Node* temp = head->next;
        head->next = ptr;
        ptr->next = temp;
        ptr->prev = head;
        temp->prev = ptr;
    }

    void deleteNode(Node* ptr)
    {
        Node* ptrPrev = ptr->prev;
        Node* ptrNext = ptr->next;
        ptrPrev->next = ptrNext;
        ptrNext->prev = ptrPrev;
    }
    
    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        head->next = tail;
        tail->prev = head;

    }

    int get(int key)
    {
        // Write your code here

        if(mp.find(key) != mp.end())
        {
            Node* recentNode = mp[key];
            int val = recentNode->value;
            mp.erase(key);
            deleteNode(recentNode);
            addNode(recentNode);
            mp[key] = head->next;
            return val;
        }

        return -1;


    }

    void put(int key, int value)
    {
        // Write your code here

        if(mp.find(key) != mp.end())
        {
            Node* recentNode = mp[key];
            mp.erase(key);
            deleteNode(recentNode);
        }

        if(mp.size() == cap)
        {
           Node* recentNode = tail->prev;
           mp.erase(recentNode->key);
           deleteNode(recentNode);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = head->next;

    }
};

