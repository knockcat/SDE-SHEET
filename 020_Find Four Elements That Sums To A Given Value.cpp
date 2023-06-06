#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            int k = j+1, l = n-1;

            while(k < l)
            {
                int currSum = arr[i] + arr[j] + arr[k] + arr[l];

                if(currSum == target)
                    return "Yes";
                else if(currSum < target)
                    ++k;
                else
                    --l;
            }
        }
    }

    return "No";
}
