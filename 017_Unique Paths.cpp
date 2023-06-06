#include <bits/stdc++.h> 

int helper(int i, int j, int n, int m, vector<vector<int>>& dp)
{
	if(i >= n or j >= m)
		return 0;
	if(i == n-1 and j == m-1)
		return 1;
	
	if(dp[i][j] != -1)
		return dp[i][j];

	return dp[i][j] = helper(i+1, j,n,m, dp) + helper(i, j+1,n ,m, dp);
}


int uniquePaths(int m, int n) {
	// Write your code here.

	vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

	return helper(0, 0, m, n, dp);

}
