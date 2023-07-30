// Time Complexity -> O(n*n)
// space Complexity -> O(n*n)

#include<bits/stdc++.h>

int lcs(string s, string t)
{
	//Write your code here

	int n = s.size(), m = t.size();

	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i = n-1; i >= 0; --i)
	{
		for(int j = m-1; j >= 0; --j)
		{
			if(s[i] == t[j]){
				dp[i][j] = 1 + dp[i+1][j+1];
			}
			else{
				dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
			}
		}
	}

	return dp[0][0];
}

// Time Complexity -> O(n*n)
// space Complexity -> O(n)

#include<bits/stdc++.h>

int lcs(string s, string t)
{
	//Write your code here

	int n = s.size(), m = t.size();

	vector<int> prev(m+1,0),curr(m+1,0);

	for(int i = n-1; i >= 0; --i)
	{
		for(int j = m-1; j >= 0; --j)
		{
			if(s[i] == t[j]){
				curr[j] = 1 + prev[j+1];
			}
			else{
				curr[j] = max(prev[j], curr[j+1]);
			}
		}
		prev = curr;
	}

	return curr[0];
}
