// Time Complexity -> O(n^3)
// Space Complexity -> O(n^2)

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.

    vector<vector<int>> mat(n+1, vector<int>(n+1, 1e9));

    for(int i =0 ; i <= n; ++i)
        mat[i][i] = 0;

    for(auto& itr : edges)
    {
        int u = itr[0];
        int v = itr[1];
        int dist =  itr[2];

        mat[u][v] = dist;
    }

    for(int k = 0; k <= n; ++k)
    {
        for(int i = 0; i <= n; ++i)
        {
            for(int j = 0; j <= n; ++j)
            {
                if(mat[i][k] != 1e9 and mat[k][j] != 1e9)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    return mat[src][dest];
}
