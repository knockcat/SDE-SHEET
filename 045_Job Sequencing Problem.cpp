// TC -> O(n (log n)) + O(n * maxDeadline) => O(n * maxDeadline)
// SC -> O(maxDeadline)

#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here

    int n = jobs.size();
    
    int maxProfit = 0, maxDeadline = 0;

    sort(jobs.begin(), jobs.end(), [&](const vector<int> &a, const vector<int> &b){
    return a[1] > b[1];
});

    for(auto itr : jobs)
        maxDeadline = max(maxDeadline, itr[0]);
    
    vector<bool> slots(maxDeadline + 1, false);

    for(int i = 0; i < n; ++i)
    {
        for(int j = jobs[i][0]; j > 0; --j)
        {
            if(!slots[j])
            {
                slots[j] = true;
                maxProfit += jobs[i][1];
                break;
            }
        }
    }

    return maxProfit;
}


// Another Approach

// TC -> O(N *log max(N, maxDeadline))
// SC -> O(maxDeadline)

#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here

    int n = jobs.size();

    int maxProfit = 0, maxDeadline = 0;

    sort(jobs.begin(), jobs.end(), [&](const vector<int>&a, const vector<int>& b){
        return a[1] > b[1];
    });

    for(auto itr : jobs)
        maxDeadline = max(maxDeadline, itr[0]);

    set<int, greater<int>> used;

    for(int i = 1; i <= maxDeadline; ++i)
        used.insert(i);
    
    for(int i = 0; i < n; ++i)
    {
        int currDeadline = jobs[i][0];

        if(used.empty() or currDeadline < *used.rbegin())
            continue;
        
        int availableSlot = *used.lower_bound(currDeadline);

        maxProfit += jobs[i][1];
        
        used.erase(availableSlot);
    }

    return maxProfit;
}


