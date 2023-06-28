// TC -> O(2^n * n)
// SC -> O(n)

include <bits/stdc++.h> 

bool isPalindrome(int start, int end, string& str)
{

    while(start < end)
    {
        if(str[start++] != str[end--])
            return false;
    }

    return true;
}

void helper(int idx, string s, int n, vector<string> ds, vector<vector<string>>& ans)
{
    if(idx == n)
    {
        ans.push_back(ds);
        return;
    }

    for(int i = idx; i < n; ++i)
    {
        if(isPalindrome(idx, i, s))
        {
            ds.push_back(s.substr(idx, i - idx + 1));

            helper(i+1, s, n, ds, ans);

            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.

    int n = s.size();

    vector<vector<string>> ans;

    vector<string> ds;

    helper(0, s, n, ds, ans);

    return ans;
}
