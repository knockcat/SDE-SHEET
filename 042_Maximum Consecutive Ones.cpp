#include<bits/stdc++.h>

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.

    int i = 0, j = 0;
    int ans = 0;

    int zeroCnt = 0;

    while(j < n)
    {
        if(arr[j] == 0)
            ++zeroCnt;

        while(zeroCnt > k)
        {
            if(arr[i++] == 0)
                --zeroCnt;
        }
        
        ans = max(ans, j-i+1);

        ++j;
    }

    return ans;
}
