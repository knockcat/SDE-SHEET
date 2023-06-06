#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.

	set<vector<int>> st;

	sort(arr.begin() , arr.end());

	vector<vector<int>> ans;

	for(int i = 0; i < n-2; ++i)
	{
		int j = i+1, k = n-1;

		while(j < k)
		{
			int sum = arr[i] + arr[j] + arr[k];

			if(sum == K)
			{
				ans.push_back({arr[i],arr[j],arr[k]});
				++j, --k;
			}
			else if(sum < K)
				++j;
			else
				--k;
		}
	}
  sort(ans.begin(), ans.end());

  ans.erase(unique(ans.begin(), ans.end()), ans.end());

  return ans;
}
