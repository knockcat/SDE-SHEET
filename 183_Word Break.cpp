// Time Complexity -> O(n*n)
// Space Complexity -> O(n)

#include <bits/stdc++.h> 

bool helper(int idx, string& target, int n, unordered_set<string>& st, vector<int>& dp)
{
    if(idx == target.size())
        return true;
    
    if(dp[idx] != -1)
        return dp[idx];

    string temp = "";
    
    for(int i = idx; i < target.size(); ++i)
    {
        temp += target[i];
        
        if(st.find(temp) != st.end())
        {
            if(helper(i+1, target, n, st, dp))
                return dp[i] = true;
        }
    }

    return dp[idx] = false;
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.

    unordered_set<string> st;

    vector<int> dp(target.size()+1, -1);
    
    for(auto& itr : arr)
        st.insert(itr);
    
    return helper(0, target, n, st, dp);

}

// Time Complexity -> O(n*n*n)
// Space Complexity -> O(n)

#include <bits/stdc++.h> 
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.

    int m = target.size();

    unordered_set<string> st;
    
    vector<int> dp(m, 0);
    
    for(auto& itr : arr)
        st.insert(itr);

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            string temp = target.substr(j, i - j + 1);
            if(st.find(temp) != st.end())
            {
                if(j > 0)
                    dp[i] += dp[j-1];
                else
                    dp[i] += 1;
            }
        }
    }

    // cout<<dp[m-1]<<endl;
    return dp[m-1] > 0;
}

// Time Complexity -> O(n*n)
// Space Complexity -> O(n)

#include <bits/stdc++.h> 
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.

    int m = target.size();

    unordered_set<string> st;
    
    vector<int> dp(m, 0);
    
    for(auto& itr : arr)
        st.insert(itr);

    for(int i = 0; i < m; ++i)
    {
        string temp;
        for(int j = i; j < m; ++j)
        {
            temp += target[j];
            if(st.find(temp) != st.end())
            {
                if(i > 0)
                    dp[j] += dp[i-1];
                else
                    dp[j] += 1;
            }
        }
    }

    return dp[m-1] > 0;
}
