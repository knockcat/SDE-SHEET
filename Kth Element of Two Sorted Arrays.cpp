Time Complexity -> O(n)
Space Cmplexity -> O(1)

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.

    int i = 0, j = 0;

    int ans = -1;

    while(i < m and j < n and k > 0)
    {
        if(row1[i] <= row2[j])
        {
            ans = row1[i];
            ++i;
        }
        else
        {
            ans = row2[j];
            ++j;
        }
        --k;
    }

    while(i < m and k > 0)
    {
        ans = row1[i++];
        --k;
    }

    while(j < n and k > 0)
    {
        ans = row2[j++];
        --k;
    }
    
    return ans;

}


// Time Complexity -> O(min(log(n), log(m)) )
// Space Cmplexity -> O(1)

#include<bits/stdc++.h>

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int n, int m, int k) {
    // Write your code here.

    if(n > m)
        return ninjaAndLadoos(row2, row1, m, n, k);
    
    int low = max(0,k - m), high = min(k, n);

    while(low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        int left = (cut1 == 0 ? INT_MIN : row1[cut1-1]);
        int left2 = (cut2 == 0 ? INT_MIN: row2[cut2-1]);

        int right = (cut1 == n ? INT_MAX : row1[cut1]);
        int right2 = (cut2 == m ? INT_MAX : row2[cut2]);

        if(left <= right2 and left2 <= right)
        {
            return max(left, left2);
        }
        else if(left >= right2)
        {
            high = cut1-1;
        }
        else
        {
            low = cut1+1;
        }
    }
    return 1;
}
