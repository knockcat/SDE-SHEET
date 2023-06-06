#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.

   int n = arr.size();

   unordered_map<int,int> mp;

   vector<vector<int>> ans;

   for(int i = 0; i < n; ++i )
   {
      if(mp[s- arr[i]])
      {
         int times = mp[s-arr[i]];

         while(times--)
         {
            ans.push_back({min(arr[i], s-arr[i]), max(arr[i], s-arr[i])});
         }
      }
      ++mp[arr[i]];
   }

   sort(ans.begin(), ans.end());
   
   return ans;
}
