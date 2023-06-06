#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.

    int n = arr.size();
    
    int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;

    for(auto itr : arr)
    {
        if(itr == num1)
            ++cnt1;
        else if(itr == num2)
            ++cnt2;
        else if(cnt1 == 0){
            num1 = itr;
            cnt1 = 1;
        }
        else if(cnt2 == 0)
        {
            num2 = itr;
            cnt2 = 1;
        }
        else
            --cnt1 , --cnt2;
    }

    cnt1 = cnt2 = 0;

    for(auto itr : arr)
    {
        if(itr == num1)
            ++cnt1;
        if(itr == num2)
            ++cnt2;
    }
    vector<int> v;

    if(cnt1 > n/3)
        v.push_back(num1);
    if(cnt2 >  n/3)
        v.push_back(num2);

    return v;

}
