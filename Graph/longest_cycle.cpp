/*
Problem Link: https://leetcode.com/problems/longest-cycle-in-a-graph/
Editorial: https://leetcode.com/problems/longest-cycle-in-a-graph/solution/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n);
        vector<int> indegree(n);
        
        for(int edge: edges)
        {
            if(edge != -1)
                indegree[edge]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        while(!q.empty())
        {
            int node = q.front(); 
            q.pop();
            vis[node] = true;
            
            int it = edges[node];
            if(it != -1)
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                int it = edges[i];
                int cnt = 1;
                vis[it] = true;
                
                //iterate in cycle
                while(it != i)
                {
                    vis[it] = true;
                    cnt++;
                    it = edges[it];
                }
                ans = max(cnt, ans);
            }
        }
        return ans;
    }
};
