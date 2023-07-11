// Time Complexity -> O(n)
// Space Complexity -> O(n)

#include<bits/stdc++.h>

string reverseString(string &str){
	// Write your code here.	

	int n = str.size();

	stack<string> st;

	string cur = "";

	for(int i = 0; i < n; ++i)
	{
		if(str[i] == 32)
		{
			if(!cur.empty())
			{
				st.push(cur);
				cur.clear();
			}
		}
		else
			cur += str[i];
	}
	
	if(!cur.empty())
		st.push(cur);

	string ans;

	while(!st.empty())
	{
		ans += st.top();
		if(st.size() > 1)
			ans += " ";
		st.pop();
	}

	return ans;
}

// Time Complexity -> O(n)
// Space Complexity -> O(1)

string reverseString(string &str){
	// Write your code here.	

	int n = str.size();

	string ans;

	for(int i = n-1; i >= 0; --i)
	{
		if(str[i] == ' ')
		{
			continue;
		}
		else
		{
			if(ans.length() > 0)
			{
				ans.push_back(' ');
			}

			int j = i;
			
			while(j >= 0 and str[j] != ' ')
			{
				--j;
			}

			ans.append(str.substr(j+1, i - j));
			
			i = j;
		}
	}

	return ans;
}
