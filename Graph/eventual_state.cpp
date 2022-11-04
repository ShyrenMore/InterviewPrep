#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/uRbJ1OF9aYM
// Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.


class Solution
{
private:
    bool dfsCheck(int node, vector<vector<int>> adj, vector<int> &visited, vector<int> &path_visited)
    {
        visited[node] = 1;
        path_visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                if (dfsCheck(it, adj, visited, path_visited))
                    return true;
            }
            else if (path_visited[it])
            {
                // node visited and on same path
                return true;
            }
        }

        path_visited[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> visited(V, 0);
        vector<int> path_visited(V, 0);
        vector<int> safe_node;
        // check[V]
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                (dfsCheck(i, graph, visited, path_visited));
            }
        }

        for (int i = 0; i < V; i++)
            if(!path_visited[i])
                safe_node.push_back(i);

        return safe_node;
    }
};