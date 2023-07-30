// Time Complexity -> O(n*m)
// Space Complexity -> O(n*m) + O(n+m) recursion stack space

#include <bits/stdc++.h> 

int helper(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    if(i == n-1 and j == m-1)
        return grid[i][j];
    if(i >= n or j >= m)
        return INT_MAX;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    int take = grid[i][j] + min(helper(i+1,j, n, m, grid, dp), helper(i, j+1, n,m, grid, dp));

    return dp[i][j] = take;
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.

    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return helper(0, 0, n, m, grid, dp);
}
