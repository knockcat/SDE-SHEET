
// TC -> O(2^n)
// SC -> O(n * (2^n))

void helper(int idx, int sum, int n, vector<int> ds, vector<int>& arr, vector<vector<int>>& ans, int k)
{
    if(idx == n)
    {
        if(sum == k)
        {
            ans.push_back(ds);
        }
        return;
    }

    ds.push_back(arr[idx]);
    sum += arr[idx];

    helper(idx+1, sum, n, ds, arr, ans, k);

    ds.pop_back();
    sum -= arr[idx];

    helper(idx+1, sum, n, ds, arr, ans, k);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.

    vector<vector<int>> ans;
    vector<int> ds;

    helper(0, 0, n, ds, arr, ans, k);

    return ans;
}


// TC -> O(n * (2^n))
// SC -> O(n * (2^n))

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.

    int range = 1 << n;

    vector<vector<int>> ans;

    for(int mask = 0; mask < range; ++mask)
    {

        vector<int> ds;
        int sum = 0;
        
        for(int i = 0; i < n; ++i)
        {
            if(mask & (1 << i))
            {
                sum += arr[i];
                ds.push_back(arr[i]);
            }
        }

        if(sum == k)
            ans.push_back(ds);
    }

    return ans;
}
