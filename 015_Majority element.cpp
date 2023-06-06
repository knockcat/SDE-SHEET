#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.

	int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;


	for(int i = 0; i < n; ++i)
	{
		if(arr[i] == num1)
			++cnt1;
		else if(arr[i] == num2)
			++cnt2;
		else if(cnt1 == 0)
		{
			num1 = arr[i];
			cnt1 = 1;
		}
		else if(cnt2 == 0)
		{
			num2 = arr[i];
			cnt2 = 1;
		}
		else
			--cnt1, --cnt2;
	}

	cnt1 = 0, cnt2 = 0;

	for(int i = 0; i < n; ++i)
	{
		if(arr[i] == num1)
			++cnt1;
		if(arr[i] == num2)
			++cnt2;
	}

	vector<int> v;
	if(cnt1 > n/2)
		v.push_back(num1);
	if(cnt2 > n/2)
		v.push_back(num2);

	if(v.empty())
		return -1;
	return v[0];
}
