// Time Complexity -> O(n log(n))
// Space Complextiy -> O(n)

#include <bits/stdc++.h> 

class heap
{
  private:
    vector<int> arr;
  public:
    heap()
    {
      
    }

    void insert(int val)
    {
        arr.push_back(val);

        int idx = arr.size()-1;

        while(idx >= 0)
        {
            int par = (idx-1) >> 1;

            if(arr[par] > arr[idx])
            {
                swap(arr[par], arr[idx]);
                idx = par;
            }
            else
                return;
        }
    }

    int deleteFromHeap()
    {
        if(arr.empty())
            return -1;
        
        int ans = arr[0];

        arr[0] = arr.back();

        arr.pop_back();

        int n = arr.size(), idx = 0;

        while(idx < n)
        {
            int leftIdx = (2*idx) + 1;
            int rightIdx =  (2*idx) + 2;

            if(leftIdx < n and arr[leftIdx] < arr[idx])
            {
              if (arr[leftIdx] < arr[rightIdx]) {
                swap(arr[leftIdx], arr[idx]);
                idx = leftIdx;
              } else {
                  swap(arr[rightIdx], arr[idx]);
                  idx = rightIdx;
              }
            }
            else if(rightIdx < n and arr[rightIdx] < arr[idx])
            {
                swap(arr[rightIdx], arr[idx]);
                idx = rightIdx;
            }
            else
                break;
        }

        return ans;
    }
    
};


vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    
    vector<int> ans;

    heap h;

    for(auto itr : q)
    {
        if(itr[0] == 0)
        {
            h.insert(itr[1]);
        } else {
          int cur = h.deleteFromHeap();

          if (cur != -1)
            ans.push_back(cur);
        }
    }

    return ans;
    
}
