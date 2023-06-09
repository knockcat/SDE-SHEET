#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.

    int n = prices.size();

    int ans = 0, mini = INT_MAX;

    for(int i = 0; i < n; ++i)
    {
        mini = min(mini, prices[i]);

        ans = max(ans, prices[i] - mini);
    }

    return ans;

}
