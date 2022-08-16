#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> &isVisited, vector<int> adj[])
    {
        isVisited[node] = 1;
        for(auto neighbour: adj[node])
        {
            if(!isVisited[neighbour])
            {
                dfs(neighbour, isVisited, adj);
            }

        }
    }

public : 
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // convert matrix to list
        int v = isConnected.size();
        vector<int> adj[v];
        vector<int> isVisited(v, 0);
        
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if(isConnected[i][j] == 1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < v; i++)
        {
            if(!isVisited[i])
            {
                ans++;
                dfs(i, isVisited, adj);
            }
        }

        return ans;
    }
};