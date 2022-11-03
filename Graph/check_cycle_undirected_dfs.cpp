#include <bits/stdc++.h>
using namespace std;

class Solution{

private:
    bool dfsCheck(int node, int parent, vector<int> adj[], vector<int> &visited)
    {
        visited[node] = 1;
        for(auto it: adj[node])
        {
            if(!visited[it])
                if(dfsCheck(it, node, adj, visited))
                    return true;
            else if(it != parent)
                return true;
        }

        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++){
            if(dfsCheck(i, -1, adj, visited))
                return true;
        }

        return false;
    }
};