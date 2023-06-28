// TC -> O(2^n)
// SC -> O(n)

#include<bits/stdc++.h>

void helper(int idx, int sum, int target, int n, vector<int> ds, vector<int>& arr, vector<vector<int>>& ans)
{
	if(sum == target)
	{
		ans.push_back(ds);
		return;
	}

	for(int i = idx; i < n; ++i)
	{
		if(i != idx and arr[i] == arr[i-1])
			continue;

		if(sum + arr[i] > target)
			break;

		sum += arr[i];
		ds.push_back(arr[i]);

		helper(i+1, sum, target, n, ds, arr, ans);

		sum -= arr[i];
		ds.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.

	sort(arr.begin(), arr.end());

	vector<int> ds;

	vector<vector<int>> ans;

	helper(0, 0, target, n, ds, arr, ans);

	return ans;
}
