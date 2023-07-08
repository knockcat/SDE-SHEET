// Time Complexity = O(m * (log(sum(arr)))
// Space Complexity = O(1)

#include <bits/stdc++.h> 

bool findMax(vector<int>& time, int n, long long  mid)
{
	long long sum = 0, cnt = 1;

	for(int i = 0; i < time.size(); ++i)
	{
		if(sum + time[i] <= mid)
		{
			sum += time[i];
		}
		else
		{
			++cnt;
			sum = time[i];
		}
	}

	return (cnt <= n);
}


long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.

	long long low = *max_element(time.begin(), time.end());
	long long high = accumulate(time.begin(), time.end(),0ll);

	long long ans = 0;

	while(low <= high)
	{
		long long mid = (low + high) >> 1;

		if(findMax(time,n, mid))
		{
			ans = mid;
			high = mid-1;
		}
		else
			low = mid+1;
	}

	return ans;
}
