// Time Complexity -> o(n * k (log (k)))
// Space Complexity -  O(n * k)

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 

    int n = kArrays.size();

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;

    for(int i = 0; i < n; ++i)
    {
        pq.push({kArrays[i][0],{i,0}});
    }

    vector<int> ans;
    
    while(!pq.empty())
    {
        auto curr = pq.top(); 
        
        auto val = curr.first;

        int i = curr.second.first, j  = curr.second.second;
        
        pq.pop();
        
        ans.push_back(val);
        
        if(j + 1 < kArrays[i].size()) 
        {
            pq.push({kArrays[i][j+1],{i, j+1}});
        }
    }

    return ans;
}


#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 

    priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>> > pq;

    for(auto itr : kArrays)
        pq.push(itr);

    vector<int> ans;

    while(!pq.empty())
    {
        vector<int> cur = pq.top();
        pq.pop();
        ans.push_back(cur[0]);;

        cur.erase(cur.begin());

        if(!cur.empty())
            pq.push(cur);
    }

    return ans;
}


#include <bits/stdc++.h> 

vector<int> merge(vector<int>& a, vector<int>& b)
{
    int i = 0, j = 0;
    int n = a.size(), m = b.size();

    vector<int> here;

    while(i < n and j < m)
    {
        if(a[i] <=  b[j])
        {
            here.push_back(a[i++]);
        }
        else
        {
            here.push_back(b[j++]);
        }
    }

    while(i < n)
    {
        here.push_back(a[i++]);
    }

    while(j < m)
    {
        here.push_back(b[j++]);
    }

    return here;
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 

    for(int i = k-1; i >= 1; --i)
    {
        kArrays[i-1] = merge(kArrays[i-1], kArrays[i]);
    }

    return kArrays[0];
}

