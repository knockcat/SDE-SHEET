// Time Complexity -> O(V + E)
// Space Complexity ->  O(N)

bool dfs(int sv, vector<int> adj[], vector<bool>& visited, vector<bool>& pathVisited)
{
  visited[sv] = pathVisited[sv] = true;

  for(auto itr : adj[sv])
  {
    if(!visited[itr])
    {
      if(dfs(itr, adj, visited, pathVisited))
        return true;
    }
    else if(pathVisited[itr])
      return true;
  }

  pathVisited[sv] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

    vector<int> adj[n+1];

    for(auto itr : edges)
    {
      int u = itr.first;
      int v = itr.second;

      adj[u].push_back(v);
    }

    vector<bool> visited(n+1,false), pathVisited(n+1,false);

    for(int i = 0; i < n; ++i)
    {
      if(!visited[i])
      {
        if(dfs(i,adj, visited, pathVisited))
          return true;
      }
    }

    return false;
}
