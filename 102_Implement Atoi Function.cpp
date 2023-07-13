// Time Complexity -> O(n)
// Space Complexity -> O(1)

#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.

    int n = str.size(), num = 0;
    
    for(int i = 0; i < n; ++i)
    {
        if(str[i] >= '0' and str[i] <= '9')
        {
            num = num * 10 + (str[i] - '0');
        }
    }

    if(n >= 0)
    {
        if(str[0] == '-')
            num *= -1;
    }

    return num;
}
