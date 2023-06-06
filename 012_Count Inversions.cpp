#include <bits/stdc++.h> 

long long merge(int lb, int mid, int ub,long long *arr, vector<long long>& temp)
{
    int i = lb, j = mid, k = lb;

    long long inversions = 0;

    while(i <= mid-1 and j <= ub)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversions += (mid - i);
        }
    }

    while(i <= mid-1)
    {
        temp[k++] = arr[i++];
    }
    while(j <= ub)
    {
        temp[k++] = arr[j++];
    }

    for(int i = lb ; i <= ub; ++i)
        arr[i] = temp[i];

    return inversions;
}

long long mergeSort(int start,  int end , long long *arr, vector<long long>& temp)
{
    int inversions = 0;
    if(start < end)
    {
        long long mid = start + (end - start)/2;
        inversions += mergeSort(start, mid, arr, temp);
        inversions += mergeSort(mid+1, end, arr, temp);
        inversions += merge(start, mid+1, end, arr, temp);
    }

    return inversions;
}

long long getInversions(long long *arr, int n){
    // Write your code here.

    vector<long long> temp(n);

    return mergeSort(0, n-1, arr, temp);

}
