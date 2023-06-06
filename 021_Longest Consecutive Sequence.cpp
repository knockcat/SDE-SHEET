#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.

    unordered_map<int,int> mp;

    for(auto itr : arr)
        ++mp[itr];
    
    int maxLength = 1;

    for(int i = 0; i < n; ++i)
    {
        if(mp.find(arr[i]-1) == mp.end())
        {
            int currLength = 1;

            int num = arr[i];
            while(mp.find(num + 1) != mp.end())
            {
                ++num;
                ++currLength;
                maxLength = max(maxLength, currLength);
            }
        }
    }

    return maxLength;
}
