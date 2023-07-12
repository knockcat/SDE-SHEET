// Time Complexity -> O(n^2)
// Space Complexity -> O(n)

#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.

    int n = price.size();

    vector<int> ans;

    for(int i = 0; i < n; ++i)
    {
        int cnt = 0;

        for(int j = i; j >= 0; --j)
        {
            if(price[j] <= price[i])
                ++cnt;
            else
                break;
        }
        ans.push_back(cnt);
    }

    return ans;
}

// Time Complexity -> O(n)
// Space Complexity -> O(2n)

#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.

    int n = price.size();

    vector<int> ans(n,0);

    stack<int> st;

    for(int i = 0; i < n; ++i)
    {
        while(!st.empty() and price[st.top()] <= price[i])
            st.pop();

        if(st.empty())
            ans[i] = i+1;
        else
            ans[i] = i - st.top();
        
        st.push(i);
    }

    return ans;
}
