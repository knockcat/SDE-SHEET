// Time Complexity -> O(n)
// Space Complexiy -> O(k)

#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here

    int i = 0, j = 0, n = arr.size();

    vector<int> ans;

    unordered_map<int,int> mp;

    while(j < n)
    {
        ++mp[arr[j]];

        if(j - i + 1 == k)
        {
            ans.push_back(mp.size());

            --mp[arr[i]];
            if(mp[arr[i]] == 0)
                mp.erase(arr[i]);
            ++i;
        }

        ++j;
    }

    return ans;	
}
