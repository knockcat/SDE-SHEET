// Time Complexity -> O(n log(k))
// Space Complexity -> O(n)

#include <algorithm>

class Kthlargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    int curr;

    Kthlargest(int k, vector<int> &arr) {
       
        curr = k;

        for(auto itr : arr)
        {
          if (pq.size() == curr) {
            pq.pop();
          }
            pq.push(itr);
        }

    }

    int add(int num) {

       pq.push(num);

       if(pq.size() >= curr)
       {
           pq.pop();
       }
       return pq.top();
    }

};
