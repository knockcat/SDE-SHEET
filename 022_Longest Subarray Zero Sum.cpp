#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here

  int n = arr.size();

  map<int,int> mp;

  mp.insert({0, -1});

  int sum = 0, ans = 0;

  for(int i = 0; i < n ; ++i)
  {
    sum += arr[i];
    if(mp.find(sum) != mp.end())
    {
      ans = max(ans, i - mp[sum]);
    }
    else
      mp.insert({sum,i});
  }

  return ans;

}
