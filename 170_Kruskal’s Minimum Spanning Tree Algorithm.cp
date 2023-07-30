// Time Complexity -> O(m*log(m) + n)
// Space Complexity -> O(n + m)

#include<bits/stdc++.h>

class DSU{
	private:
		vector<int> rank, parent, size;

	public:
		DSU(int n)
		{
			rank.resize(n+1, 0);
			size.resize(n+1, 1);
			parent.resize(n+1);

			for(int i = 0; i <= n; ++i)
				parent[i] = i;
		}

		int findParent(int u)
		{
			if(parent[u] == u)
				return u;
			return parent[u] = findParent(parent[u]);
		}

		void unionByRank(int u, int v)
		{
			int parU = findParent(u);
			int parV = findParent(v);

			if(parU == parV)
				return;
			
			if(rank[parU] < rank[parV])
			{
				parent[parU] = parV;
			}
			else if(rank[parV] < rank[parV]){
				parent[parV] = parU;
			}
			else{
				parent[parV] =  parU;
				++rank[parU];
			}
		}

		void unionBySize(int u, int v)
		{
			int parU = findParent(u);
			int parV = findParent(v);

			if(parU == parV)
				return;
			
			if(size[parU] < size[parV])
			{
				parent[parU] = parV;
				size[parV] += size[parU];
			}
			else{
				parent[parV] = parU;
				size[parU] += size[parV];
			}
		}

		bool isSame(int u, int v)
		{
			return findParent(u) == findParent(v);
		}

};

int kruskalMST(int n, vector<vector<int>> &edges)
{
	// Write your code here.

	sort(edges.begin(), edges.end(),[&](vector<int> &a, vector<int> &b){
		return a[2] < b[2];
	});

        int mstWt = 0;

	DSU dsu(n);

	for(auto& itr : edges)
	{
		int u = itr[0];
		int v = itr[1];
		int wt = itr[2];

		if(dsu.isSame(u, v))
			continue;
		else
		{
			mstWt += wt;
			dsu.unionBySize(u, v);
		}
	}

	return mstWt;
}
