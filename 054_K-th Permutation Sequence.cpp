TC -> O(n*n)
SC -> O(n)

#include<bits/stdc++.h>

string kthPermutation(int n, int k) {
    // Write your code here.

    int fact = 1;

    vector<int> v;

    for(int i = 1; i < n; ++i)
    {
        fact *= i;
        v.push_back(i);
    }

    v.push_back(n);

    --k;

    string ans;

    while(true)
    {
        ans.push_back(v[k/fact] + '0');

        v.erase(v.begin()+k/fact);

        if(v.empty())
            break;
        
        k %= fact;

        fact /= v.size();
    }

    return ans;
    
}
