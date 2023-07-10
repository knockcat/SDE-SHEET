// Time Complexity -> O(n)
// Space Complexity -> O(n)

bool isValidParenthesis(string s)
{
    // Write your code here.

    int n = s.size();

    stack<char> st;

    for(int i = 0; i < n; ++i)
    {
        if(st.empty())
            st.push(s[i]);
        else
        {
              if (!st.empty() and st.top() == '(' and s[i] == ')' or
                  st.top() == '{' and s[i] == '}' or st.top() == '[' and s[i] == ']')
                    st.pop();
              else
                st.push(s[i]);
        }
    }

    return st.empty();
}
