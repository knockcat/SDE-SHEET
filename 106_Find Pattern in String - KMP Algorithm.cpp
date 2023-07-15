// Time Complexity -> O(n+m)
// space Complexity ->O(n+m+1)

#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    // Write your code here.

    int m = p.size();

    string c = p;
    c += '#';
    c += s;

    int n = c.length();

    vector<int> lps(n,0);

    int  j = 0;
    for(int i = 1; i < n; ++i)
    {
        int j = lps[i-1];

        while(j > 0 and c[i] != c[j])
            j = lps[j-1];
        
        if(c[i] == c[j])
            ++j;
        lps[i] = j;

        if(lps[i] == m)
            return true;
    }
    return false;
}

// Time Complexity -> O(n+m)
// space Complexity ->O(patern length)

#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    // Write your code here.

    int n = s.size();
    
    int m = p.size();

    vector<int> lps(m,0);

    int  j = 0;
    for(int i = 1; i < m; ++i)
    {
        int j = lps[i-1];

        while(j > 0 and p[i] != p[j])
            j = lps[j-1];
        
        if(p[i] == p[j])
            ++j;
        lps[i] = j;
    }
    
    int i = 0;
    j = 0;

    while(i < n)
    {
        if(s[i] == p[j])
        {
            ++i,++j;
        }
        else if(s[i] != p[j])
        {
            if(j == 0)
                ++i;
            else
                j = lps[j-1];

        }

        if(j == m)
            return true;
    }
    return false;
}
