// Time Complexity ->  O(n*n)
// Space Complexity -> O(n*n) + O(n) recursion stack space

int helper(int idx, int n, vector<int>& price, vector<vector<int>>& dp)
{
	if(idx == price.size())
		return 0;
	
	if(dp[idx][n] != -1)
		return dp[idx][n];

	int rodLength = idx+1;

	int notTake = helper(idx+1, n, price, dp);

	int take = 0;

	if(rodLength <= n)
	{
		take = price[rodLength - 1] + helper(idx, n - rodLength, price, dp);
	}

	return dp[idx][n] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.

	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

	return helper(0, n, price, dp);
}

// Time Complexity ->  O(n*n)
// Space Complexity -> O(n*n) 

int cutRod(vector<int> &price, int n) {
  // Write your code here.

 vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for (int rodLength = 1; rodLength <= n; rodLength++) {
        for (int currentLength = 1; currentLength <= n; currentLength++) {
            int idx = rodLength - 1;

            int notTake = dp[rodLength-1][currentLength];
            int take = 0;
            if (currentLength >= rodLength) {
                take = price[idx] + dp[rodLength][currentLength - rodLength];
            }

            dp[rodLength][currentLength] = max(take, notTake);
        }
    }

    return dp[n][n];
}
