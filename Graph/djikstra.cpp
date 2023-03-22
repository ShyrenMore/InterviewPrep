/*
Problem link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
Editorial: https://takeuforward.org/data-structure/dijkstras-algorithm-using-priority-queue-g-32/
Video: https://youtu.be/V6H1qAeB-l4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V+1, 1e9);
        dist[S] = 0; 
        vector<int> parent(V+1);
        for(int  i = 1; i <= V; i++)
            parent[i] = i;
        pq.push({0, S});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            int u = it.second;
            int currDist = it.first;
            pq.pop();
            for(auto v: adj[u])
            {
                int node = v[0];
                int edgeWeight = v[1];
                if(currDist + edgeWeight < dist[node])
                {
                    dist[node] = currDist + edgeWeight;
                    pq.push({dist[node], node});
                    parent[node] = u;
                }
            }
        }
        
        // if there is no path b/w src and destination
        return dist;
    }
};
