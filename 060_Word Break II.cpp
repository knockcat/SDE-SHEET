// Time Complexity -> O(2^N)
// Space Complexity -> O(n) + O(n)

#include <bits/stdc++.h> 

void helper(int idx, int st,  string str, string& s, map<string,int>& mp, vector<string>& ans)
{
    if(idx == s.size())
    {
      if (str.back() == ' ')
      {
        str.pop_back();
        ans.push_back(str);
      }
      return;
    }

    str += s[idx];
 
    string cur = str.substr(st);

    if(mp.find(cur) != mp.end())
    {
        str += " ";

        helper(idx+1, str.size(), str, s, mp, ans);
        
        str.pop_back();

        helper(idx+1, st,  str,s, mp, ans);
    }
    else
    {
        helper(idx+1,st, str, s, mp, ans);
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here

    vector<string> ans;

    string str = "";

    map<string, int> mp;

    for(auto itr : dictionary)
        ++mp[itr];

    helper(0, 0, str, s, mp, ans);

    return ans;

}
