// Time Complexity -> O(n (log(k))
// Space Complexti -> O(k)

#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.

	priority_queue<int, vector<int> , greater<int> > pq;

	sort(a.rbegin(), a.rend());
	sort(a.rbegin(), a.rend());

	vector<int> ans;

	for(int i = 0; i < n; ++i)
	{
		for(int j =0 ; j < n; ++j)
		{
			int sum = a[i] + b[j];

			if(pq.size() < k)
			{
				pq.push(sum);
			}
			else if(sum > pq.top())
			{
				pq.pop();

				pq.push(sum);
			}
		}
	}

	while(!pq.empty())
	{
		ans.push_back(pq.top());
		pq.pop();
	}

	sort(ans.rbegin(), ans.rend());

	return ans;
}
