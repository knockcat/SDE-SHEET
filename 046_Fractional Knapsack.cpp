#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    

    sort(items.begin(),items.end(), [&](pair<int,int>&a ,pair<int,int> &b)
    {
        return (double)a.second/a.first > (double)b.second/b.first;
    });

    double profit = 0;

    for(int i = 0; i < n; ++i)
    {
        if(w - items[i].first >= 0)
        {
            profit += items[i].second;
            w -= items[i].first;
        }
        else
        {
            profit += w*(double)items[i].second/items[i].first;
            break;
        }
        
    }
    
    return profit;
}
