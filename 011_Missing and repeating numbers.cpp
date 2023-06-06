#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here

	sort(arr.begin(), arr.end()) ;

	int here = 1;

	for(int i = 0; i < n; ++i)
	{
		if(here == arr[i])
			++here;
		else if(arr[i] == here-1)
			continue;
		else if(here != arr[i])
		{
			break;
		}
	}

	unordered_map<int,int> mp;

	for(auto itr : arr)
		++mp[itr];
	
	int here2;

	for(auto itr : mp)
	{
		if(itr.second == 2)
		{
			here2 = itr.first;
			break;
		}
	}
	
	return {here, here2};

}
