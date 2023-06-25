#include<algorithm>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.

    int n = start.size();

    vector<pair<int,int> >  here;

    for(int i = 0; i < n; ++i)
    {
      here.push_back({start[i], finish[i]});
    }

    sort(here.begin(), here.end(), [&](pair<int,int>&a, pair<int,int>&b){
        return a.second < b.second;
    });

    int cnt = 0, end = -1;

    for(int i = 0; i < n; ++i)
    {
       if(here[i].first >= end)
       {
           ++cnt;
           end = here[i].second;
       }
    }

    return cnt;
}
