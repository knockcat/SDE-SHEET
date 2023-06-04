#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.

     vector<vector<long long int>> res;

     vector<long long int> prev;

     for(int i = 0; i < n; ++i)
     {
        vector<long long int> curr(i+1,1);

        if(i < 2)
        {
          
        }
        else
        {
          for(int i = 1; i < prev.size(); ++i)
          {
           curr[i] = prev[i] + prev[i-1];
          }
        }

        res.push_back(curr);

        prev = curr;
     }
     return res;
}
