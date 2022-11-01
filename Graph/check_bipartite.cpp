#include <bits/stdc++.h>
using namespace std;

/*
https://youtu.be/-vu34sct1g8
*/

class Solution
{

private:
    bool check(int start, vector<vector<int>> graph, vector<int> &color)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : graph[node])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                    return false;

            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();
        // convert matrix to list
        
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
            if(color[i] == -1)
            {
                if (check(i, graph, color) == false)
                    return false;
            }
        return true;
    }
};