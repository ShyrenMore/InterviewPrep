/*
problem link: https://leetcode.com/problems/combination-sum-iii/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void findCombinations(int idx, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &ds, int k)
    {
        if (idx == arr.size())
        {
            if (target == 0 && k == 0)
                ans.push_back(ds);
            return;
        }

        if (arr[idx] <= target)
        {
            ds.push_back(arr[idx]);
            findCombinations(idx + 1, arr, target - arr[idx], ans, ds, k - 1);
            ds.pop_back();
        }

        findCombinations(idx + 1, arr, target, ans, ds, k);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> arr;
        for (int i = 1; i <= 9; i++)
            arr.push_back(i);

        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, arr, n, ans, ds, k);
        return ans;
    }
};