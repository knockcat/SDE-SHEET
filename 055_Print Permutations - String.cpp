// TC -> O(n * N!)
// SC -> O(n)

#include <bits/stdc++.h> 

void helper(vector<int> freq, int n,string ds, string &s, vector<string>& ans )
{
    if(ds.size() == n)
    {
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i < n; ++i)
    {
        if(freq[i] == 0)
        {
            ds.push_back(s[i]);
            freq[i] = 1;

            helper(freq, n, ds, s, ans);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.

    int n = s.size();
    
    vector<int> freq(n,0);

    string ds;

    vector<string> ans;

    helper(freq,n, ds, s, ans);

    return ans;
}

// TC -> O(n * N!)
// SC -> O(1)

#include <bits/stdc++.h>

void helper(int idx, int n, string& s, vector<string>& ans)
{
  if (idx == n) {
    ans.push_back(s);
    return;
  }

    for(int i = idx; i < n; ++i)
    {
        swap(s[i], s[idx]);
        helper(idx+1, n, s, ans);
        swap(s[i], s[idx]);
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.

    int n = s.size();
    
    vector<string> ans;

    helper(0, n, s, ans);

    return ans;
}
