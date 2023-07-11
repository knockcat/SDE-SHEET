// Time Complexity -> O(n^2)
// Space Complexity -> O(n^2)

string longestPalinSubstring(string str)
{
    // Write your code here.

    int n = str.size();

    int maxi = INT_MIN;

    string ans;

    vector<vector<int>> dp(n, vector<int>(n,0));

    for(int diff = 0; diff < n; ++diff)
    {
        for(int i = 0, j = i + diff; i < n, j < n; ++i, ++j)
        {
            if(i == j)
            {
                dp[i][j] = 1;
            }
            else if(diff == 1)
            {
                dp[i][j] = (str[i] == str[j] ? 2 : 0);
            }
            else{
                if(str[i] == str[j])
                {
                    if(dp[i+1][j-1] > 0)
                        dp[i][j] = dp[i+1][j-1] + 2;
                    else
                        dp[i][j] = 0;
                }
            }

            if(dp[i][j] > maxi)
            {
                maxi = (j - i + 1);

                ans = str.substr(i, j - i + 1);
            }
        }
    }

    return ans;
}

// Time Complexity -> O(n^2)
// Space Complexity -> O(1)


string helper(string& str, int start, int end)
{
    int n = str.size();

    while(start >= 0 and end < n and str[start] == str[end])
    {
        --start, ++end;
    }

    return str.substr(start+1, end-start-1);
}

string longestPalinSubstring(string str)
{
    // Write your code here.

    int n = str.size();

    string ans;

    int start = 0, end = 0, maxi =0 ;

    for(int i = 0; i < n; ++i)
    {
        string oddCase = helper(str, i, i);

        if(oddCase.length() > maxi)        
        {
            ans = oddCase;
            maxi = oddCase.length();
        }

        string evenCase = helper(str, i, i+1);
        
        if(evenCase.length() > maxi)
        {
            ans = evenCase;
            maxi = evenCase.length();
        }
    }

    return ans;
}
