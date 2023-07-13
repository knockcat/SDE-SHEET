// Time Complexity -> O(N^2)
// Space Complexity -> O(N)

#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.

    vector<int> ans;

    for(int win = 1; win <= n; ++win)
    {
        int i = 0, j = 0;

        list<int> l;
        int maxi = INT_MIN;

        while(j < n)
        {
            while(!l.empty() and l.back() > a[j])
                l.pop_back();
            
            l.push_back(a[j]);
           
            if(j - i + 1 == win)
            {
                maxi = max(maxi, l.front());

                if (a[i] == l.front()) {
                  l.pop_front();
                }
                ++i;
            }
            ++j;
        }

        ans.push_back(maxi);
    }

    return ans;
}


// Time Complexity -> O(N)
// Space Complexity -> O(3N)


#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.

    vector<int> left(n, 0), right(n,0), ans(n,INT_MIN);

    stack<int> st;

    for(int i = 0; i < n; ++i)
    {
        while(!st.empty() and a[st.top()] >= a[i])
            st.pop();
        if(st.empty())
            left[i] = 0;
        else
            left[i] = st.top() + 1;
        
        st.push(i);
    }

    while(!st.empty())
        st.pop();

    for(int i = n-1; i >= 0; --i)
    {
        while(!st.empty() and a[st.top()] >= a[i])
            st.pop();
        if(st.empty())
            right[i] = n-1;
        else
            right[i] = st.top() - 1;
            
        st.push(i);
    }

    for(int i = 0; i < n; ++i)
    {
        ans[right[i] - left[i]] = max(ans[right[i] - left[i]], a[i]);
    }

    for(int i = n-2; i >= 0; --i)
    {
        ans[i] = max(ans[i], ans[i+1]);
    }

    return ans;
};
