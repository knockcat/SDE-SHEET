// Time Complexity -> O(2^n) string is becoming double after every iteration
// Space Complexity -> O(1)

#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	// Write your code here.	

	string str = "1";

	--n;

	while(n--)
	{
		string ans;
		
		int cnt = 1;
		
		for(int i = 1; i < str.size(); ++i)
		{
			if(str[i] == str[i-1])
				++cnt;
			else
			{
				ans += cnt + '0';
				ans += str[i-1];
				cnt = 1;
			}
		}

		if(cnt >= 1)
		{
			ans += cnt + '0';
			ans += str[str.size()-1];
		}

		str = ans;
	}

	return str;
}
