// Time Complexity -> O(n*k)
// Space Complexity ->  O(n*k) + O(n) auxiliary stack space

#include <bits/stdc++.h> 

bool helper(int idx, int n, int k, vector<int>& arr, vector<vector<int>>& dp)
{
    if(idx == n)
    {
        if(k == 0)
            return true;
        return false;
    }

    if(dp[idx][k] != -1)
        return dp[idx][k];

    bool notTake = helper(idx+1, n, k, arr,dp);
    bool take = false;
    if(arr[idx] <= k)
    {
        take = helper(idx+1, n, k - arr[idx], arr,dp);
    }

    dp[idx][k] = take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

    return helper(0, n, k, arr, dp);
}

// Time Complexity -> O(n*k)
// Space Complexity ->  O(n*k) 

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    
    for(int i = 0; i < n; ++i)
        dp[i][0] = true;
    
     dp[0][arr[0]] = true;

    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j <= k; ++j)
        {
            bool notTake = dp[i-1][j];
            
            bool take = false;

            if(arr[i] <= j)
                take = dp[i-1][j-arr[i]];
            
            dp[i][j] = take | notTake;
        }
    }
    
    return dp[n-1][k];
}

// Time Complexity -> O(n*k)
// Space Complexity ->  O(k+1) 

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    vector<bool> prev(k+1, false), curr(k+1, false);
    
    prev[0] = curr[0] = true;
    
     prev[arr[0]] = true;

    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j <= k; ++j)
        {
            bool notTake = prev[j];
            
            bool take = false;

            if(arr[i] <= j)
                take = prev[j-arr[i]];
            
            curr[j] = take | notTake;
        }
        prev = curr;
    }
    
    return curr[k];
}
