/*
Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
Video: https://youtu.be/q_a6lpbKJdw

Approach:
Traverse every node
for each node: assign vertical(col) and level(row)

Carry a queue and ordered_map
q will store (node, col, row)
map will have vertical as key
it's value will be another map<(level)int, (nodes)multiset<int>>
we used multiset since we need repeated values

Now start level order traversal
Initially insert (root, 0, 0) in q
while(!q.empty())
- pop and insert it DS
- push it's children in Q
- root.left will be push as (root.left, col-1, row+1)
since we are going lower left diagnoally
- root.right will be pused as (root.right, col+1, row+1)
since we are going lower right diagnoally

*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    TreeNode *left, *right;
    int val;
    TreeNode(int x)
    {
        this->val = x;
    }
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> ans;
        queue<pair<TreeNode *, pair<int, int>>> q;

        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto pr = q.front();
            q.pop();
            TreeNode *node = pr.first;
            int col = pr.second.first;
            int row = pr.second.second;
            ans[col][row].insert(node->val);
            if (node->left)
                q.push({node->left, {col - 1, row + 1}});
            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }

        vector<vector<int>> res;
        for (auto p : ans) // p: <int, map<int, multiset<int>>>
        {
            vector<int> col;
            for (auto q : p.second)      // q: map<int, multiset<int>>
                for (auto el : q.second) // el: element of multiset
                    col.push_back(el);
            res.push_back(col);
        }

        return res;
    }
};