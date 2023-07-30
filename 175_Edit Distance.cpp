// Time Complexity -> O(n*m)
// Space Complexity -> O(n*m) + O(n+m)  auxiliary stack space

#include <bits/stdc++.h>

int helper(int i, int j, int n, int m, string &str1, string &str2,
           vector<vector<int>> &dp) {
  if (i == n and j == m)
    return 0;

  if (i == n)
    return m - j;

  if (j == m)
    return n - i;

  if (dp[i][j] != -1)
    return dp[i][j];

  int take = 0;

  if (str1[i] == str2[j]) {
    take = 0 + helper(i + 1, j + 1, n, m, str1, str2, dp);
  } else {
    take = 1 + min({helper(i + 1, j, n, m, str1, str2, dp),
                    helper(i, j + 1, n, m, str1, str2, dp),
                    helper(i + 1, j + 1, n, m, str1, str2,dp)});
  }

  dp[i][j] = take;
}

int editDistance(string str1, string str2) {
  // write you code here

  int n = str1.size(), m = str2.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

  return helper(0, 0, n, m, str1, str2, dp);
}
