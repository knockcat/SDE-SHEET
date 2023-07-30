// Time Complexity -> O(n*n)
// space Complexity -> O(n*n) + O(n) recursion stack space

#include <bits/stdc++.h> 

int helper(int idx, int prev, int n, vector<int>& rack, vector<vector<int>>& dp)
{
	if(idx == n)
		return 0;
	
	if(dp[idx][prev + 1] != -1)
		return dp[idx][prev+1];

	int notTake = helper(idx+1, prev, n, rack, dp);

	int take = 0;

	if(prev == -1 or rack[idx] > rack[prev])
	{
		take = rack[idx] + helper(idx+1, idx, n , rack , dp);
	}

	dp[idx][prev+1] = max(take, notTake);
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here

	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

	return helper(0, -1, n, rack, dp);
}
