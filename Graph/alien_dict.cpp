/*
GFG link: https://practice.geeksforgeeks.org/problems/alien-dictionary/1
Video link: https://youtu.be/U3N_je7tWAs
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    
    private:
    vector<int> topo(int V, vector<int>adj[])
    {
        int indegree[V] = {0};
        for(int i = 0; i < V; i++)
        {
            for(auto it: adj[i])
                indegree[it]++;
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> order;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            order.push_back(node);
            
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        return order;
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i = 0; i < N-1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            for(int j = 0; j < len; j++)
            {
                if(s1[j] != s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int> order = topo(K, adj);
        string ans = "";
        for(auto x: order)
            ans+=(x+'a');
        
        return ans;
    }
};
