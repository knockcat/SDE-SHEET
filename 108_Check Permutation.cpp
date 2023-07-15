// Time Complexity -> O(n)
// Space Complexity -> O(n)

#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.

    int n = str1.size(), m = str2.size();

    if(n != m)
        return false;

    vector<int> hash(26, 0);

    for(int i = 0; i < n; ++i)
    {
        ++hash[str1[i]-'a'];
        --hash[str2[i]-'a'];
    }

    for(int i = 0; i < 26; ++i)
    {
        if(hash[i])
            return false;
    }

    return true;
}

// Time Complexity -> O(n)
// Space Complexity -> O(n)

#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2;
}
