#include <vector>
#include <iostream>
using namespace std;

class Solution
{

private:
    void dfs(int node, vector<int> adj[], int isVisited[], vector<int> &sequence)
    {
        isVisited[node] = 1;
        sequence.push_back(node);

        for(auto neighbour: adj[node])
        {
            if (!isVisited[neighbour])
                dfs(neighbour, adj, isVisited, sequence);
        }
    }

public:
    vector<int> DFS(int V, vector<int> adj[])
    {
        int isVisted[V] = {0};
        int startNode = 0;
        vector<int> sequence;
        dfs(startNode, adj, isVisted, sequence);
    }
};