// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int V, vector<pair<int, int>> &prerequisites)
    {
        // Code here
        vector<int> adj[V];
        for (auto it : prerequisites)
            adj[it.second].push_back(it.first);

        int indegree[V] = {0};
        for (int node = 0; node < V; node++)
            for (auto it : adj[node])
                indegree[it]++;

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return (topo.size() == V) ? true : false;
        // return topo;
    }
};