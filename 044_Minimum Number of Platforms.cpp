// Brute I did at First Glance

// TC -> O(n(log n )) + O(n * n)
// SC -> O(n) + O(n*n)

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.


    vector<pair<int,int>> vp;

    for(int i = 0; i < n; ++i)
        vp.push_back({at[i], dt[i]});
    
    sort(vp.begin(), vp.end());

    vector<vector<int>> ans;

    for(auto itr : vp)
    {
        bool ok = false;
        if(ans.empty())
        {
            ans.push_back({itr.second});
        }
        else
        {
            int startTime = itr.first, endTime = itr.second;

            for(int i = 0; i < ans.size(); ++i)
            {
                if(ans[i].back() < startTime)
                {
                    ans[i].push_back(endTime);
                    ok = true;
                    break;
                }
            }

            if(!ok)
                ans.push_back({itr.second});
        }
    }

    return ans.size();
}

// I tried to optimise it

// TC -> O(n(log n )) + O(n (log n))
// SC -> O(n) + O(n)

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.


    vector<pair<int,int>> vp;

    for(int i = 0; i < n; ++i)
        vp.push_back({at[i], dt[i]});
    
    sort(vp.begin(), vp.end());

    vector<vector<int>> ans;

    priority_queue<int, vector<int>, greater<int> > pq;

    for(auto itr : vp)
    {
        int startTime = itr.first, endTime = itr.second;

        if(pq.empty())
        {
            pq.push(endTime);
        }
        else{
            int currTime = pq.top();

            if(currTime < startTime)
            {
                pq.pop();
            }
            
            pq.push(endTime);
        }
    }
    
    return pq.size();
}

// Other Possible Approaches and more Optimised

// this approach is based on the fact that if a train is arrived than only it can depart
// there by we will just sort arrival and departure time arrays
// we will just keep track of trains that are arriving and increase the number of platfoms and if a train departs we will decrease the platform count because the platfoms is vacant now.
// the ans will me max count of plaforms at any point of time.

// TC -> O(n(log n )) + O(n (log n))
// SC -> O(1)

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.

    sort(at, at + n);
    sort(dt ,dt + n);

    int platforms = 0, ans = 0;

    int i = 0, j = 0;

    while(i < n and j < n)
    {
      if (at[i] <= dt[j]) {
        ++platforms;
        ++i;
      } else {
        --platforms;
        ++j;
      }

      ans = max(ans, platforms);
    }

    return ans;
}

// Another approach first with brute

// TC -> O(n*n)
// SC -> O(2360) = O(1) can termed as constant space

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.

    // we can keep a prefix array which will tell the max platforms needed at a given time.

    vector<int> pref(2360, 0);

    int ans = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = at[i]; j <= dt[i]; ++j)
        {
            ++pref[j];
            
            ans = max(ans, pref[j]);
        }
    }

    return ans;
}

// Optimised version of above approach using cumilative sum

// TC -> O(n) + O(2360)
// SC -> O(2360) = O(1) can termed as constant space

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.

    // we can keep a prefix array which will tell the max platforms needed at a given time.

    // cumilative sum

    vector<int> pref(2360, 0);

    int ans = 0;

    for(int i = 0; i < n; ++i)
    {
        ++pref[at[i]];
        --pref[dt[i]+1];
    }

    for(int i = 1; i < 2360; ++i)
    {
        pref[i] += pref[i-1];
        ans = max(ans, pref[i]);
    }

    return ans;
}
