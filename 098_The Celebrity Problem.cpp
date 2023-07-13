// Time Complexity -> O(n*2)
// Space Complexity -> O(2n)


#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.

	 vector<int> indegree(n,0), outdegree(n,0);

	 for(int i = 0; i < n; ++i)
	 {
		 for(int j = 0; j < n; ++j)
		 {
			 if(knows(i,j))
			 {
				 ++indegree[j];
				 ++outdegree[i];
			 }
		 }
	 }

	 for(int i = 0; i < n; ++i)
	 {
		 if(indegree[i] == n-1 and outdegree[i] == 0)
		 	return i;
	 }

	 return -1;
}


// Time Complexity -> O(n+m)
// Space Complexity -> O(1)

#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.

	 for(int i = 0; i < n; ++i)
	 {
		 int cnt = 0;

		 for(int j = 0; j < n; ++j)
		 {
			 if(i == j)	continue;
			 if(i != j and knows(j,i) and !(knows(i,j)))
			 	++cnt;
			 else
			 	break;
		 }

		 if(cnt == n-1)
		 	return i;
	 }

	 return -1;
}

// Time Complexity -> O(n)
// Space Complexity -> O(n)

#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.

	 stack<int> st;

	 for(int i = 0; i < n; ++i)
	 	st.push(i);
		
	 while(st.size() > 1)
	 {
		 int first = st.top();
		 st.pop();

		 int second = st.top();
		 st.pop();

		 if(knows(first, second))
		 	st.push(second);
		 else
		 	st.push(first);
	 }

	 int celebrity = st.top();

	 int cnt = 0;
	 
	 for(int i = 0; i < n; ++i)
	 {
		 if(knows(i, celebrity) and !knows(celebrity,i))
			++cnt;
	 }

	 if(cnt == n-1)
	 	return celebrity;
	 return -1;
}

// Time Complexity -> O(n)
// Space Complexity -> O(1)

#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.

	 int start = 0, end = n-1;

	 while(start < end)
	 {
		 if(knows(start, end))
		 	++start;
		  else
		  	--end;
	 }
	 
	 int celebrity = start;

	 int cnt = 0;
	 
	 for(int i = 0; i < n; ++i)
	 {
		 if(knows(i, celebrity) and !knows(celebrity,i))
			++cnt;
	 }

	 if(cnt == n-1)
	 	return celebrity;
	 return -1;
}
