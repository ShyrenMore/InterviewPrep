#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution{
public:

    vector<int> BFS(int V, vector<int> adj[])
    {
        int isVisited[V] = {0};
        isVisited[0] = 1;
        queue<int> q;
        q.push(0);

        vector<int> sequence;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            sequence.push_back(node);

            // pushing neighbours
            for(int neighbour: adj[node])
            {
                if(!isVisited[neighbour])
                {
                    isVisited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }

        return sequence;
    }
};