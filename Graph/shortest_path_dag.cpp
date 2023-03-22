/*
Problem link: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
Editorial: https://takeuforward.org/data-structure/shortest-path-in-directed-acyclic-graph-topological-sort-g-27/
Video: https://www.youtube.com/watch?v=ZUFQfFaU-8U&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=28
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void topo(int u, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
    {
        vis[u] = 1; //1
        
        for(auto it: adj[u])    // 3
        {
            int v = it.first;
            if(!vis[v])
                topo(v, adj, vis, st);
        }
        
        st.push(u); //2
    }
    
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
    
        vector<pair<int, int>> adj[N];
        for(auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }
        
        // topo sort
        int vis[N] = {0};
        stack<int> st;
        for(int i = 0; i < N; i++)
        {
            if(!vis[i])
                topo(i, adj, vis, st);
        }
        
        // actual algo
        int src = 0;
        vector<int> dist(N, INT_MAX);
        dist[src] = 0;
        while(!st.empty())
        {
            int u = st.top();
            st.pop();
            
            
            if(dist[u] != INT_MAX) // for -ve weight cycle
            // prevents the algorithm from updating the dist value for a node that hasn't been visited yet.
            {
                for(auto it: adj[u])
                {
                    int v = it.first;
                    int wt = it.second;
                    
                    if(dist[u] + wt < dist[v])
                        dist[v] = dist[u] + wt;
                }
            }
        }
        
        for(int i = 0; i < N; i++)
        {
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};
