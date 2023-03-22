/*
GFG: https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
Editorial: https://takeuforward.org/data-structure/g-35-print-shortest-path-dijkstras-algorithm/
Video: https://youtu.be/rp1SMw7HSO8
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>>adj[n+1];
        for(auto it: edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // min-heap for {dist, node}
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9);
        dist[1] = 0; 
        vector<int> parent(n+1);
        for(int  i = 1; i <= n; i++)
            parent[i] = i;
        pq.push({0, 1});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            int u = it.second;
            int currDist = it.first;
            pq.pop();

            for(auto edge: adj[u])
            {
                int v = edge.first;
                int edgeWeight = edge.second;
                if(currDist + edgeWeight < dist[v])
                {
                    dist[v] = currDist + edgeWeight;
                    pq.push({dist[v], v});
                    parent[v] = u;
                }
            }
        }
        
        // if there is no path b/w src and destination
        if(dist[n] == 1e9)  return {-1};
        
        vector<int> path;
        int node = n;
        // Iterate backwards from destination to source through the parent array.
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        
        reverse(path.begin(), path.end());
        return path;
    }
};
