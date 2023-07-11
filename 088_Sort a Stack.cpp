// Time Complexity -> O(N^2)
// Space Complexity -> O(N)

#include <bits/stdc++.h> 

void insert(stack<int>& stack, int ele)
{
	if(stack.size() == 0 or stack.top() <= ele)
	{
		stack.push(ele);
	}
	else
	{
		int temp = stack.top();

		stack.pop();

		insert(stack, ele);

		stack.push(temp);
	}
	return;
}

void helper(stack<int>& stack)
{
	if(stack.size() <= 1)
		return ;
	
	int temp = stack.top();
	stack.pop();

	helper(stack);

	insert(stack, temp);
}

void sortStack(stack<int> &stack)
{
	// Write your code here

	helper(stack);

}
