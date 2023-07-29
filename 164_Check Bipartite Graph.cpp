// Time Complexity -> O(V + E)
// Space Complexity -> O(V)

bool isBipartite(int sv,vector<int> adj[], vector<int> color)
{
	if(color[sv] == -1)
		color[sv] = 1;
	
	for(auto itr : adj[sv])
	{
		if(color[itr] == -1)
		{
			color[itr] = 1 - color[sv];

			if(!isBipartite(itr, adj, color))
				return false;
		}
		else if(color[itr] == color[sv])
			return false;
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.

	int n = edges.size();

	vector<int>  adj[n+1];

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(edges[i][j] == 1)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	vector<int> color(n+1, -1);

	for(int i = 0; i < n; ++i)
	{
		if(color[i] == -1)
		{
			if(!isBipartite(i, adj, color))
				return false;
		}
	}

	return true;
}
