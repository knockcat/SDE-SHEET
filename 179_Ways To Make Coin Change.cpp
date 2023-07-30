// Time Complexity -> O(n*value)
// Space Complexity -> O(n*value) + O(n) auxiliary stack 

#include<bits/stdc++.h>

long helper(int idx, int value, int* denominations, vector<vector<long>>& dp)
{
    if(idx == 0)
    {
        return (value % denominations[0] == 0);
    }

    if(dp[idx][value] != -1)
        return dp[idx][value];

    long notTake = helper(idx-1, value, denominations, dp);

    long take = 0;

    if(denominations[idx] <= value)
        take = helper(idx, value - denominations[idx], denominations, dp);
    
    return dp[idx][value] = take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here

    vector<vector<long>> dp(n+1, vector<long>(value+1, -1));
    return helper(n-1, value, denominations, dp);

}

// Time Complexity -> O(n*value)
// Space Complexity -> O(n*value)

#include<bits/stdc++.h>

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here

    vector<vector<long>> dp(n+1, vector<long>(value+1, 0));

    for(int i =0 ; i <= value; ++i)
    {
        dp[0][i] = (value % denominations[0] == 0);
    }

    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j <= value; ++j)
        {
            long notTake = dp[i-1][j];
            long take = 0;
            
            if(denominations[i] <= j)
                take = dp[i][j - denominations[i]];

            dp[i][j] = take + notTake;
        }
    }

    return dp[n-1][value];
}

// Time Complexity -> O(n*value)
// Space Complexity -> O(n)

#include <bits/stdc++.h>

long countWaysToMakeChange(int *denominations, int n, int value) {
  // Write your code here

  vector<long> prev(value + 1, 0), curr(value + 1, 0);

  for (int i = 0; i <= value; ++i) {
    prev[i] = (value % denominations[0] == 0);
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= value; ++j) {
      long notTake = prev[j];
      long take = 0;

      if (denominations[i] <= j)
        take = curr[j - denominations[i]];

      curr[j] = take + notTake;
    }
    prev = curr;
  }

  return prev[value];
}
