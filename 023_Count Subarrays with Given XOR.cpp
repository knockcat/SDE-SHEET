#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.

    unordered_map<int,int> mp;

    int n = arr.size();

    int prefXor = 0;
    int cnt = 0;

    for(int i = 0; i < n; ++i)
    {
        prefXor ^= arr[i];

        if(prefXor == x)
            ++cnt;

        int y = prefXor ^ x;    

        cnt += mp[y];

        ++mp[prefXor];
    }

    return cnt;
}
