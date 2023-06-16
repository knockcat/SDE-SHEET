#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.

    long start = 0, end = n-1, ans = 0;
    
    long maxLeft = arr[start], maxRight = arr[end];

    while(start <= end)
    {
        maxLeft = max(arr[start], maxLeft);
        maxRight = max(arr[end], maxRight);
        ans += min(maxLeft, maxRight) - min(arr[start], arr[end]);

        if(arr[start] < arr[end])
            ++start;
        else
            --end;
    }
    
    return ans;
    
}
