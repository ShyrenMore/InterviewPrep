#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.

Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
*/

class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        
        vector<int> indegree(V, 0);
        vector<int> ans;

        // preparing indegree array
        for (int i = 0; i < V; i++)
        {
            for (auto it: adj[i])
            {
                indegree[it]++;
            }
        }

        // pushing nodes with indegree 0 in Q
        queue<int> q;
        for (int i = 0; i < V; i++)
            if(indegree[i] == 0)
                q.push(i);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }
};