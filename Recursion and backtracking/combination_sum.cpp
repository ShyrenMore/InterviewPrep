/*
Given an array of distinct int and target int,
return list of all unique combinations of array where chosen nos sum to target
You may return the combinations in any order

ip: arr = [2, 3, 6, 7]  target = 7
op: [[2, 2, 3], [7]]

ip: arr = [2, 3, 5] target = 8
op: [[2, 2, 2, 2], [2, 3, 3,], [3, 5]]

ip: arr = [2], target = 1
op: []

link: https://leetcode.com/problems/combination-sum/

Whenever there is question of printing combination or subsequences: 
- recursion should be first thought

Whenever problem is related to picking up els in an array 
we start thinkinh in pick and non-pick thot process

f(idx, target, curr_sum) are definitely going to be parameters 
since we need to print the combination we need a vector for it: f(int idx, int target, int curr_sum, vector<int>  ans)
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void findCombinations(int idx, vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (idx == candidates.size())
        {
            if (target == 0)
                ans.push_back(ds);
            return;
        }

        if (candidates[idx] <= target)
        {
            ds.push_back(candidates[idx]);
            findCombinations(idx, candidates, target - candidates[idx], ans, ds);
            ds.pop_back();
        }

        findCombinations(idx + 1, candidates, target, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, candidates, target, ans, ds);
        return ans;
    }
};
