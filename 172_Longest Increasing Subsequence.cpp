// Time Complexity -> O(n log(n))
// Space Complexity -> O(n)

#include<bits/stdc++.h>

int helper(int idx, int prev, int arr[], int n, vector<vector<int>>& dp)
{
    if(idx == n)
        return 0;
    
    if(dp[idx][prev+1] != -1)
        return dp[idx][prev+1];

    int notTake = helper(idx+1, prev, arr, n, dp);

    int take = 0;

    if(prev == -1 or arr[idx] > arr[prev])
    {
        take = 1 + helper(idx+1, idx, arr, n, dp);
    }

    dp[idx][prev+1] = max(take, notTake);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here

    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));

    return helper(0, -1, arr, n, dp);
}


// Time Complexity ->  O(n*n)
// Space Complexity -> O(n*n) + o(n) recursion stack space

#include<bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here

    vector<int> temp;

    temp.push_back(arr[0]);

    for(int i = 1; i < n; ++i)
    {
        if(arr[i] > temp.back())
            temp.push_back(arr[i]);
        else{
            auto idx = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[idx] = arr[i];
        }
    }

    return temp.size();
}
