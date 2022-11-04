#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.

Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.

https://youtu.be/5lZ0iJMrUMk
*/

class Solution{
private:
    void dfs(int node, vector<int> &visited, stack<int> &st, vector<int> adj[])
    {
        visited[node] = 1;
        for(int neighbour: adj[node])
        {
            if(!visited[neighbour])
                dfs(neighbour, visited, st, adj);
        }

        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
            if(!visited[i])
                dfs(i, visited, st, adj);

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};