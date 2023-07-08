// Time Complexity -> min(O(log(n), log(m)))
// Space Complexity -> O(1)

double median(vector<int>& a, vector<int>& b) {
	// Write your code here.

	int n = a.size(), m = b.size();

	int low = 0, high = n-1;

	while(low <= high)
	{
		int cut1 = (low + high) >> 1;
		int cut2 = (n + m + 1) >> 1 - cut1;

		int left1 = (cut1 == 0 ? INT_MIN : a[cut1-1]);
		int left2 = (cut2 == 0 ? INT_MIN : b[cut2-1]);

		int right1 = (cut1 == n ? INT_MAX : a[cut1]);
		int right2 = (cut2 == m ? INT_MAX : b[cut2])

		if(left1 <= right2 and left2 <= right1)
		{
			if((n + m) & 1)
				return max(left1, left2);
			else
				return max(left1 ,left2) + min(right1 ,right2)/2.0;
		}
		else if(left1 > right2)
		{
			hight = cut1 - 1;
		}
		else
		{
			low = cut1 + 1;
		}
	}

	return 0.0;
}
