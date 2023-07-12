// Time Complexity -> O(N) overal will be O(Q*N) , where Q is number of queries.
// Space Complexity -> O(2N)

#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.

	private:

		stack<int> st1, st2;
	
	public:
		
		// Constructor

		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			st1.push(num);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(st1.empty())
				return -1;
			
			int val = st1.top();
			st1.pop();
			return val;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(!st1.empty())
			{
				return st1.top();
			}
			return -1;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			
			if(!st1.empty())
			{
				int mini = INT_MAX;

				while(!st1.empty())
				{
					mini = min(mini, st1.top());
					st2.push(st1.top());
					st1.pop();
				}

				while(!st2.empty())
				{
					st1.push(st2.top());
					st2.pop();
				}

				return mini;
			}

			return -1;
		}
};

// Time Complexity -> O(1)
// Space Complexity -> O(2N)


#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.

	private:

		stack<pair<int,int>> st;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			
			if(st.empty())
                st.push({num, num});
			else
			{
				if(num < st.top().second)
					st.push({num, num});
				else
					st.push({num, st.top().second});
			}
        }
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(!st.empty())
			{
				int val = st.top().first;
				st.pop();
				return val;
			}
			return -1;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(!st.empty())
			{
				return st.top().first;
			}
			return -1;
			
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(!st.empty())
			{
				return st.top().second;
			}
			return -1;
		}
};



// Time Complexity -> O(1)
// Space Complexity -> O(N)

#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	private:
		long long mini;
		stack<long long> st;
		
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
			while(!st.empty())
				st.pop();
			mini = INT_MAX;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			if(st.empty())
			{
				mini = num;
				st.push(num);
			}
			else{
				if(num < mini)
				{
					st.push((2 * num)*1LL - mini);
					mini = num;
				}
				else
				{
					st.push(num);
				}
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(st.empty())
				return -1;
			long long val = st.top();

			if(val < mini)
			{
				long long x = mini;
				mini = 2 * mini - val;
				st.pop();
				return x;
			}
			
			st.pop();
			return val;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.

			if(st.empty())
				return -1;
			if(st.top() < mini)
			{
				return mini;
			}
			else
				return st.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(st.empty())
				return -1;
			return mini;
		}
};
