#include <bits/stdc++.h>
using namespace std;

class Solution{
    
    private:
        bool dfsCheck(int node, vector<vector<int>> adj, vector<int> &visited, vector<int> &path_visited)
        {
            visited[node] = 1;
            path_visited[node] = 1;
            for(auto it: adj[node])
            {
                if(!visited[it])
                {
                    if(dfsCheck(it, adj, visited, path_visited))
                        return true;
                }
                else if(path_visited[it]) 
                {
                    // node visited and on same path
                    return true;
                }
            }

            path_visited[node] = 0;
            return false;
        }

    public:

    bool isCyclic(int V, vector<vector<int>> graph)
    {
        vector<int> visited(V, 0);
        vector<int> path_visited(V, 0);

        for (int i = 0; i < V; i++){
            if(!visited[i]) {
                if(dfsCheck(i, graph, visited, path_visited))
                    return true;
            }
        }

        return false;
    }
};