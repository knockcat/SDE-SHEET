#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here

    int i = 0, j = 0, n = input.size();

    unordered_map<int,int> mp;

    int ans = 0;

    while(j < n)
    {
        ++mp[input[j]];

        if(mp.size() == j- i + 1)
        {
            ans = max(ans, j-i + 1);
        }
        else
        {
            --mp[input[i]];
            if(mp[input[i]] == 0)
                mp.erase(input[i]);
            ++i;
        }
        ++j;
    }

    return ans;
}
