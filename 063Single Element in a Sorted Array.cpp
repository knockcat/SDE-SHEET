// Time Complexity -> O(log(n))
// Space Complexity -> O(1)

int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here

	int n = arr.size();

	if(n == 1)
		return arr[0];
	
	if(arr[0] != arr[1])
		return arr[0];

	if(arr[n-2] != arr[n-1])
		return arr[n-1];

	int low = 1,high = n-2;

	while(low <= high)
	{
		int mid = (low + high) >> 1;

		if(arr[mid] != arr[mid-1] and arr[mid] != arr[mid+1])
			return arr[mid];

		if(mid & 1)
		{
			if(arr[mid] == arr[mid-1])
				low = mid+1;
			else
			 	high = mid-1;
		}
		else{
			if(arr[mid] == arr[mid+1])
				low = mid+1;
			else
			 	high = mid-1;
		}
	}

	return arr[low];
}
