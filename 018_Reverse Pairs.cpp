#include <bits/stdc++.h>

int merge(int lb, int mid, int ub, vector<int>& arr, vector<int>& temp)
{
	int i = lb, j = mid, k = lb;

	int pairs = 0;

	int right = mid;

        for (int left = lb; left < mid; ++left) {
            while(right <= ub and arr[left] > 2 * arr[right])
				++right;
			
			pairs += (right - mid);
				
        }
        

	while(i <= mid-1 and j <= ub)
	{
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];
		}
	}

	while(i <= mid-1)
		temp[k++] = arr[i++];
	
	while(j <= ub)
		temp[k++] = arr[j++];

	for(int i = lb; i <= ub; ++i)
		arr[i] = temp[i];
	
	return pairs;
}

int mergeSort(int start, int end, vector<int>& arr, vector<int>& temp)
{
	int pairs = 0;

	if(start < end)
	{
		int mid = start + (end - start)/2;
		pairs += mergeSort(start, mid, arr, temp);
		pairs += mergeSort(mid+1, end, arr, temp);
		pairs += merge(start, mid+1, end, arr, temp);
	}

	return pairs;
}


int reversePairs(vector<int> &arr, int n){
	// Write your code here.	

	vector<int> temp(n);

	return mergeSort(0, n-1, arr, temp);
}
