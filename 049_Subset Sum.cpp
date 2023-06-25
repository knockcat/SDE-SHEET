// Recursive Approach

// TC -> O(2^n)
// SC -> O(n)

void helper(int idx, int sum, int n, vector<int>& num, vector<int>& ans)
{
	if(idx == n)
	{
		ans.push_back(sum);
		return;
	}

	sum += num[idx];

	helper(idx+1, sum,n, num, ans);

	sum -= num[idx];

	helper(idx+1, sum, n,num, ans);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.

	int n = num.size();

	vector<int> ans;

	helper(0, 0, n, num, ans);

	sort(ans.begin(),ans.end());

	return ans;	
}

// bitmasking

// TC -> O(n * (2^n))
// SC -> O(1)

vector<int> subsetSum(vector<int> &num){
	// Write your code here.	

	int n = num.size();
	
	vector<int> ans;
	
	for(int mask = 0; mask < (1 << n); ++mask)
	{
		int sum = 0;
		for(int i = 0; i < n; ++i)
		{
			if(mask & (1 << i))
				sum += num[i];
		}

		ans.push_back(sum);
	}

	sort(ans.begin(),ans.end());
	
	return ans;
}
