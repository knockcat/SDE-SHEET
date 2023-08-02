// Time Complexity -> O(2^n)
// Space Complexity -> O(N) recursion stack space

bool isPalindrome(int start, int end, string& str)
{
    while(start <= end)
    {
        if(str[start++] != str[end--])
            return false;
    }
    return true;
}

int helper(int idx, int n, string& str)
{
    if (idx == n) {
        return 0;
    }

    int ans = INT_MAX;

    for(int i = idx; i < n; ++i)
    {
        if(isPalindrome(idx, i, str))
        {
            int cost = 1 + helper(i+1, n, str);
            ans = min(ans, cost);
        }
    }

    return ans;
}

int palindromePartitioning(string str)
{
    // Write your code here

    int n = str.size();
    
    return helper(0, n, str)-1;

}

// Time Complexity -> O(n^2)
// Space Complexity -> O(n) + O(n) recursion stack space

bool isPalindrome(int start, int end, string& str)
{
    while(start <= end)
    {
        if(str[start++] != str[end--])
            return false;
    }
    return true;
}

int helper(int idx, int n, string& str, vector<int>& dp)
{
    if (idx == n) {
        return 0;
    }

    if(dp[idx] != -1)
        return dp[idx];

    int ans = INT_MAX;

    for(int i = idx; i < n; ++i)
    {
        if(isPalindrome(idx, i, str))
        {
            int cost = 1 + helper(i+1, n, str, dp);
            ans = min(ans, cost);
        }
    }

    return dp[idx] = ans;
}

int palindromePartitioning(string str)
{
    // Write your code here

    int n = str.size();

    vector<int> dp(n+1, -1);
    
    return helper(0, n, str, dp)-1;

}

// Time Complexity -> O(n*2)
// Space Complexity -> O(n) 

bool isPalindrome(int start, int end, string &str) {
  while (start <= end) {
    if (str[start++] != str[end--])
      return false;
  }
  return true;
}

int palindromePartitioning(string str) {
  // Write your code here

  int n = str.size();

  vector<int> dp(n + 1, 0);

  dp[n] = 0;

  for (int idx = n - 1; idx >= 0; --idx) {

    int ans = INT_MAX;

    for (int i = idx; i < n; ++i) {
      if (isPalindrome(idx, i, str)) {
        int cost = 1 + dp[i+1];
        ans = min(ans, cost);
      }
    }

    dp[idx] = ans;
  }

  return dp[0] - 1;
}
