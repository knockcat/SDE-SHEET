// Time Complexity -> O(n)
// Space Complexity -> O(n)

int romanToInt(string s) {
    // Write your code here

    unordered_map<char,int> mp;

    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    
    int n = s.size();

    int prev = -1, ans = 0;

    for(int i = n-1; i >= 0; --i)
    {
        if(prev == -1 or mp[s[i]] >= prev)
            ans += mp[s[i]];
        else
            ans -= mp[s[i]];
            
        prev = mp[s[i]];
    }

    return ans;
}
