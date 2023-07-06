// Time Complexity -> O(log(INT_MAX) * n * log(m))
// Space Complexity -> O(1)

#include<climits>

int countSmallerThanMid(vector<int>& row, int mid)
{
    int low = 0, high = row.size()-1;

    while(low <= high)
    {
        int md = (low + high)>>1;

        if(row[md] <= mid)
            low = md + 1;
        else
            high = md-1;
    }

    return low;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.

    int n = matrix.size(), m = matrix[0].size();

    int low = 1, high = 1e9;

    while(low <= high)
    {
        int mid = (low + high) >> 1;

        int cnt = 0;
        
        for(int i = 0; i < n; ++i)
        {
            cnt += countSmallerThanMid(matrix[i], mid);
        }

        if(cnt <= (n*m) >> 1)
            low = mid+1;
        else
            high = mid-1;
    }

    return low;

}
