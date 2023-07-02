// Time Complexity -> O(n^m)
// Space Complexity ->O(n)

bool isSafe(int node, int col, vector<int>& color, vector<vector<int>>& mat, int n, int m)
{
    for(int k = 0; k < n; ++k)
    {
        if(k != node and mat[k][node] == 1 and color[k] == col)
            return false;
    }

    return true;
}

bool helper(int node, vector<int>& color, vector<vector<int>>& mat, int n, int m)
{
    if(node == n)
        return true;

    for(int i = 1; i <= m; ++i)
    {
        if(isSafe(node, i, color, mat,n, m))
        {
            color[node] = i;

            if(helper(node+1, color, mat,n, m))
                return true;
            else
                color[node] = 0; 
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here

    int n = mat.size();

    vector<int> color(n,0);

    if(helper(0, color, mat, n, m))
        return "YES";
    return "NO";

}
