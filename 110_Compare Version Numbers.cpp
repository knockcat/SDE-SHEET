// Time Complexity -> O(n+m)
// Space Complexity -> O(1)

#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    // Write your code here
    
    int n = a.size(), m = b.size();

    int i = 0, j = 0;

    while(i < n or j < m)
    {
        long long x = 0, y = 0;

        while(i < n and a[i] != '.')
            x = (x*10) + a[i++]-'0';
        
        while(j < m and b[j] != '.')
            y = (y*10) + b[j++]-'0';
        
        if(x > y)
            return 1;
        if(y > x)
            return -1;
        
        ++i, ++j;
    }

    return 0;
}
