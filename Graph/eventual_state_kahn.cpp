#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<vector<int>> reverse_graph(V);
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for(auto it: graph[i])
            {
                reverse_graph[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safenodes;
        for (int i = 0; i < V; i++)
            if(indegree[i] == 0){
                q.push(i);
            }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it: reverse_graph[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }


        sort(safenodes.begin(), safenodes.end());
        return safenodes;
    }
};