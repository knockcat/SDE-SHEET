// Time Complexity -> O(n^2)
// Space Complexity -> O(n)

int minCharsforPalindrome(string str) {
	// Write your code here.

	int n = str.size(), cnt = 0;
	
	int i = 0, j = n-1, end = n-1;

	while(i < j)
	{
		if(str[i] == str[j])
		{
			++i, --j;
		}
		else{
			++cnt;
			i = 0;
			j = --end;
		}
	}
	
	return cnt;
}

// Time Complexity -> O(n+m)
// Space Complexity -> O(n+m)

#include<algorithm>

int minCharsforPalindrome(string str) {
	// Write your code here.

	string rev = str;

	reverse(rev.begin(), rev.end());

	string c = str + '$' + rev;

	int n = c.size(), m = str.size();

	vector<int> lps(n, 0);

	for(int i = 1; i < n; ++i)
	{
		int j = lps[i-1];

		while(j > 0 and c[i] != c[j])
			j = lps[j-1];
		
		if(c[i] == c[j])
			++j;

		lps[i] = j;
	}

	return m - lps[n-1];
	
}
