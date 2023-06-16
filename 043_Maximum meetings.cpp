#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.

    int n = start.size();

    vector<pair<int, pair<int,int>>> vp;

    for(int i = 0; i < n; ++i)
    {
      vp.push_back({end[i],{i+1, start[i]}});
    }

    sort(vp.begin(), vp.end());

    int prev = -1;

    vector<int> ans;

    for(auto itr : vp)
    {
      int start = itr.second.second, finish = itr.first, idx = itr.second.first;

      if(start > prev)
      {
        ans.push_back(idx);
        prev = finish;
      }
    }

    return ans;
}
