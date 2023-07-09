// Time Complexity -> O(n (log(n))
// Space Complexity -> O(n)

#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.

    unordered_map<int,int> mp;

    vector<int> ans;

    for(auto itr : arr)
        ++mp[itr];
    
    priority_queue<pair<int,int>> pq;

    for(auto itr :  mp)
        pq.push({itr.second, itr.first});

    while(k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    sort(ans.begin(), ans.end());

    return ans;
}
