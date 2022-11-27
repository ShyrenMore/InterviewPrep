/*
https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/submissions/
Discuss post: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/discuss/623673/Concise-explanation-with-a-Picture-for-Visualization
*/

class Solution {
private:
    int dfs(int node, int myCost, vector<bool>& hasApple, vector<int>& visited, vector<vector<int>> &adj)
    {
        visited[node] = 1;
        int subtreeCost = 0;
        for(auto it: adj[node])
        {
            if(!visited[it])
                subtreeCost += dfs(it, 2, hasApple, visited, adj);
        }
        
        if(subtreeCost == 0 && !hasApple[node])
            return 0;
        
        return (myCost + subtreeCost);
    }
    
public:
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> visited(n, 0);
        return dfs(0, 0, hasApple, visited, adj);
    }
};
