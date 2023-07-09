Time Complexity -> O(N*(2^N))
Space Complexity -> O(N*(2^N))

#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here

    vector<vector<int>> ans;

    int n = v.size();

    int range = 1 << n;

    for(int i = 0; i < range; ++i)
    {
       vector<int> cur;
       for(int mask = 0; mask < n; ++mask)
       {
            if(i & (1 << mask))
                cur.push_back(v[mask]);
       }
       ans.push_back(cur);
    }

    return ans;
}
