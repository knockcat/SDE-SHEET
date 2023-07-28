// Time Complexity -> O(N + M)
// Space Complexity -> O(N)

bool dfs(int sv, int par, vector<int>adj[], vector<bool>& visited)
{
    visited[sv] = true;

    for(auto itr : adj[sv])
    {
        if(!visited[itr])
        {
            if(dfs(itr, sv, adj, visited))
                return true;
        }
        else if(itr != par)
            return true;
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    vector<int> adj[n+1];

    for(auto itr : edges)
    {
        int u = itr[0];
        int v = itr[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n+1, false);

    for(int i = 1; i <= n; ++i)
    {
        if(!visited[i])
        {
            if(dfs(i, -1, adj, visited))
                return "Yes";
        }
    }

    return "No";
}
