// Time Complexity -> O(n*w)
// Space Complexity -> O(n*w) + O(n) recursion stack space

int helper(int idx, int n, int w, vector<int>& values, vector<int>& weights, vector<vector<int>>& dp)
{
	if(idx == n)
		return 0;
	
	if(dp[idx][w] != -1)
		return dp[idx][w];
	
	int notTake = helper(idx+1, n, w, values, weights, dp);

	int take = 0;

	if(weights[idx] <= w)
	{
		take = values[idx] + helper(idx+1, n, w - weights[idx], values, weights, dp);
	}

	dp[idx][w] = max(take, notTake);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here

	vector<vector<int>> dp(n+1,vector<int>(w+1,-1));

	return helper(0, n, w, values, weights,dp);
}

// Time Complexity -> O(n*w)
// Space Complexity -> O(n*w)

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
  // Write your code here

  vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= w; ++j) {

      int notTake = dp[i-1][j];

      int take = 0;

      if (weights[i-1] <= j) {
        take = values[i-1] +
               dp[i-1][j-weights[i-1]];
      }

      dp[i][j] = max(take, notTake);
    }
  }

  return dp[n][w];
}
