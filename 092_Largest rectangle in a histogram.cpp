// Time Complexity -> O(N) + O(N)  + O(N) + O(N) two passes 
// Space Complexity -> O(3N)  

#include<bits/stdc++.h> 
 
 int largestRectangle(vector < int > & heights) {
   // Write your code here.

    int n = heights.size();

    vector<int> leftSmaller(n,-1);
    vector<int> rightSmaller(n,-1);

    stack<int> st;

    for(int i = 0; i < n; ++i)
    {
      while(!st.empty() and heights[st.top()] >= heights[i])
        st.pop();
      
      if(st.empty())
        leftSmaller[i] = 0;
      else
        leftSmaller[i] = st.top()+1;

      st.push(i);
    }

    while(!st.empty())
      st.pop();

    for(int i = n-1; i >= 0; --i)
    {
      while(!st.empty() and heights[st.top()] >= heights[i])
        st.pop();
      if(st.empty())
        rightSmaller[i] = n-1;
      else
        rightSmaller[i] = st.top()-1;
      
      st.push(i);
      
    }

    int maxArea = 0;

    for(int i = 0; i < n; ++i)
    {
      int width = (rightSmaller[i] - leftSmaller[i] + 1);
      int area = width * heights[i];
      maxArea = max(maxArea, area);
    }

    return  maxArea;
 }

// Time Complexity -> O(N) + O(N)  
// Space Complexity -> O(N)  

#include<bits/stdc++.h> 
 
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   
   int n = heights.size();

   stack<int> st;

   int maxArea = 0;

   for(int i = 0; i <= n; ++i){
     while(!st.empty() and (i == n or heights[st.top()] >= heights[i]))  
     {
       int height = heights[st.top()];
       st.pop();

       int width;

       if(st.empty())
          width = i;
       else
          width = i - st.top() - 1;
        
        maxArea = max(maxArea, height * width);
     }

     st.push(i);
   }
   return maxArea;
 }
