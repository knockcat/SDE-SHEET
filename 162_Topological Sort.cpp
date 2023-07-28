// Time Complexity -> O(V + E)
// Space Complexity -> O(V)

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    vector<int> adj[v+1];

    for(auto itr : edges){
        int u = itr[0];
        int v = itr[1];

        adj[u].push_back(v);
    }

    vector<int> indegree(v,0);

    for(int i = 0; i < v; ++i)
    {
        for(auto itr : adj[i])
            ++indegree[itr];
    }

    queue<int> q;
    
    for(int i = 0; i < v; ++i)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    
    vector<int> ans;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(auto itr : adj[cur])
        {
            --indegree[itr];

            if(indegree[itr] == 0)
                q.push(itr);
        }
    }

    return ans;
}

// Time Complexity -> O(V + E)
// Space Complexity -> O(V)

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    vector<int> adj[v+1];

    for(auto itr : edges){
        int u = itr[0];
        int v = itr[1];

        adj[u].push_back(v);
    }

    vector<int> indegree(v,0);

    for(int i = 0; i < v; ++i)
    {
        for(auto itr : adj[i])
            ++indegree[itr];
    }

    queue<int> q;
    
    for(int i = 0; i < v; ++i)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    
    vector<int> ans;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(auto itr : adj[cur])
        {
            --indegree[itr];

            if(indegree[itr] == 0)
                q.push(itr);
        }
    }

    return ans;
}
