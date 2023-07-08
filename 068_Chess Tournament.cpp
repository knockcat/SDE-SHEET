// Time Complexity -> O(n(log(n)) + O((high - low) * (n))
// Space Complexity -> O(1)

// (high - low) is the maximum distance

#include <bits/stdc++.h> 

bool isPossible(vector<int>& positions, int n, int c, int cur)
{
	int prev = positions[0];

	int cnt = 1;

	for(int i = 1; i < n; ++i)
	{
		if(positions[i] - prev >= cur)
		{
			++cnt;
			prev = positions[i];
		}
	}

	return cnt >= c;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here

	sort(positions.begin(), positions.end());

	int low = 1, high = positions[n-1] - positions[0], ans = 0;

	for(int i = low; i <= high; ++i)
	{
		if(isPossible(positions, n, c, i))
		{
			ans = i;
		}
		else
			break;
	}

	return ans;
}


#include <bits/stdc++.h> 

bool isPossible(vector<int>& positions, int n, int c, int cur)
{
	int prev = positions[0];

	int cnt = 1;

	for(int i = 1; i < n; ++i)
	{
		if(positions[i] - prev >= cur)
		{
			++cnt;
			prev = positions[i];
		}
	}

	return cnt >= c;
}


// Time Complexity -> O(n(log(n)) + O(log(high - low) * (n))
// Space Complexity -> O(1)


int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here

	sort(positions.begin(), positions.end());

	int low = 1, high = positions[n-1] - positions[0], ans = 0;

	while(low <= high)
	{
		int mid = (low + high) >> 1;

		if(isPossible(positions, n, c, mid))
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid-1;	
		}
	}
	return ans;
}
