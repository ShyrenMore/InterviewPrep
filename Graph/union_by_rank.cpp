#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent;
    
    public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // func returns ultimate parent
    int findParent(int node) {
        if(node  == parent[node])
            return node;
        
        // path compression is storing the ans
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){

        // finding pu and pv
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        // u and v are in same component
        if(ulp_u == ulp_v)
            return;

        // smaller rank get attached to bigger rank
        if(rank[ulp_v] > rank[ulp_u])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // if 3 and 7 belong to same comp?
    if(ds.findParent(3) == ds.findParent(7))
        cout << "3 & 7 belong to same component\n";
    else
        cout << "3 & 7 DO NOT belong to same component\n";
    ds.unionByRank(3, 7);
    if(ds.findParent(3) == ds.findParent(7))
        cout << "3 & 7 belong to same component\n";
    else
        cout << "3 & 7 DO NOT belong to same component\n";
    return 0;
}