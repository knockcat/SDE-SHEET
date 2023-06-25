// TC -> O(2^n)
// SC -> 2 * O(2^n) + O(n) + O(n) recursion depth

#include <bits/stdc++.h> 

void helper(int idx, int n, vector<int> ds, vector<int>& arr, set<vector<int>>& used)
{
    if(idx == n)
    {
        used.insert(ds);
        return;
    }

    ds.push_back(arr[idx]);
    helper(idx+1, n , ds, arr, used);
    ds.pop_back();
    helper(idx+1, n, ds, arr, used);
}


vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.

    sort(arr.begin(), arr.end());

    set<vector<int>> used;

    vector<int> ds;

    helper(0, n, ds, arr, used);

    vector<vector<int>> ans;

    for(auto itr : used)
        ans.push_back(itr);

    return ans;
}

// Another Optimised approach space

// TC -> O((2^n) * n)
// SC -> O(2^n) + O(n) + O(n) recursion depth

#include <bits/stdc++.h> 

void helper(int idx, int n, vector<int> ds, vector<int>& arr, vector<vector<int>>& ans)
{
    ans.push_back(ds);
    
    for(int i = idx; i < n; ++i)
    {
        if(i != idx and arr[i] == arr[i-1])
            continue;
        ds.push_back(arr[i]);
        helper(i+1, n, ds, arr, ans);
        ds.pop_back();
    }
}


vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    vector<int> ds;

    helper(0, n, ds, arr, ans);

    return ans;
}
