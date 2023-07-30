// Time Complexity -> O(N^3)
// Space Complexity -> O(N^2) + O(n) auxiliary stack space

#include <bits/stdc++.h> 

int helper(int i, int j, vector<int>& arr, vector<vector<int>>& dp)
{
    if(i == j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9;

    for(int k = i; k < j; ++k)
    {
        int steps = arr[i-1] * arr[k] * arr[j] + helper(i, k, arr, dp) + helper(k+1, j, arr, dp);

        mini = min(mini, steps);
    }

    dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.

   vector<vector<int>> dp(N+1, vector<int>(N+1, -1));

    return helper(1, N-1, arr, dp);
}

// Time Complexity -> O(N^3)
// Space Complexity -> O(N^2)

#include <bits/stdc++.h>

int matrixMultiplication(vector<int> &arr, int N) {
  // Write your code here.

  vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

  for (int i = N - 1; i >= 1; --i) {
    for (int j = i + 1; j < N; ++j) {
      int mini = 1e9;

      for (int k = i; k < j; ++k) {
        int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];

        mini = min(mini, steps);
      }

      dp[i][j] = mini;
    }
  }

  return dp[1][N - 1];
}
