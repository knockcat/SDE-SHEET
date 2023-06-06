bool searchMatrix(vector<vector<int>>& mat, int target) {
        
    int n = mat.size(), m = mat[0].size();    
    int start = 0, end = (n*m)-1;

    if(n == 0 or m == 0)
        return false;

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int val = mat[mid/m][mid%m];

        if(target == val)
            return true;
        else if(target < val)
            end = mid-1;
        else
            start = mid+1;
    }

    return false;

}
