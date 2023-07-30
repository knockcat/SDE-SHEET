// Time Complexity -> O(n * m)
// Space Complexity -> O(n)

#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.

    vector<int> distance(n+1, 1e9);

    distance[src] = 0;

    for(int i = 0; i < n-1; ++i)
    {
        for(auto itr : edges)
        {
            int u = itr[0];
            int v = itr[1];
            int dist = itr[2];

            if(distance[u] != 1e9 and distance[u] + dist < distance[v])
            {
                distance[v] = distance[u] + dist;
            }
        }
    }

    return distance[dest];
}
