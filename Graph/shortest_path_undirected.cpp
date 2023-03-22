/*
Problem link: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
Editorial: https://takeuforward.org/data-structure/shortest-path-in-undirected-graph-with-unit-distance-g-28/
Video: https://www.youtube.com/watch?v=C4gxoTaI71U&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=28
*/

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        vector<int> adj[n];
        for(int i = 0; i < m; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        q.push(src);
        
        vector<int>vis(n, -1);
        vis[src] = 0;
        
        
        int level = 0;
        while(!q.empty())
        {
            int sz = q.size();
            ++level;
            
            while(sz--)
            {
                int node = q.front();
                q.pop();
                for(auto it: adj[node])
                {
                    if(vis[it] == -1)
                    {
                        q.push(it);
                        vis[it] = level;
                    }
                }
            }
        }
        return vis;
    }
};
