// Time Complexity -> O(n logn)
// Space Complexity -> O(n)

#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.

	priority_queue<int, vector<int>, greater<int> > pq;

	for(auto itr : arr)
	{
		if(pq.size() < K)
		{
			pq.push(itr);
		}
		else
		{
			int cur = pq.top();

			if(cur < itr)
			{
				pq.pop();
				pq.push(itr);
			}
		}
	}

	return pq.top();
}

// Time Complexity -> O(n log(k))
// Space Complexity -> O(k)

#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.

	priority_queue<int> pq(arr.begin(), arr.end());

	while(K-- > 1)
	{
		pq.pop();
	}

	return pq.top();
}
