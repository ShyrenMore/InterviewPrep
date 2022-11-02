#include <bits/stdc++.h>
using namespace std;

/*
https://youtu.be/-vu34sct1g8
Visited matrix: have color matrix

dfs(1, 0) = color node 1 with color 0
and call dfs(2, !0)

*/

class Solution
{

private:
    bool dfs(int node, int curr_color, vector<vector<int>> graph, vector<int> &color)
    {
        color[node] = curr_color;
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                if(dfs(it, !curr_color, graph, color) == false)
                    return false;
            }
            else if (color[it] == curr_color)
                return false;
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();

        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
            if (color[i] == -1)
            {
                if (dfs(i, 0, graph, color) == false)
                    return false;
            }
        return true;
    }
};