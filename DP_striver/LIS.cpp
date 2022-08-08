/*
problem link: https://leetcode.com/problems/longest-increasing-subsequence/
*/

#include <iostream>
#include <vector>
using namespace std;

class RecSolution
{
public:
    int f(int idx, int prev_idx, vector<int> &nums)
    {
        if (idx == nums.size())
            return 0;

        int not_take = 0 + f(idx + 1, prev_idx, nums);
        int take = 0;
        if (prev_idx == -1 || nums[idx] > nums[prev_idx])
            take = 1 + f(idx + 1, idx, nums);

        return max(take, not_take);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        return f(0, -1, nums);
    }
};

class MemoSolution
{
public:
    int f(int idx, int prev_idx, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (idx == nums.size())
            return 0;

        if (dp[idx][prev_idx + 1] != -1)
            return dp[idx][prev_idx + 1];

        int not_take = 0 + f(idx + 1, prev_idx, nums, dp);
        int take = 0;
        if (prev_idx == -1 || nums[idx] > nums[prev_idx])
            take = 1 + f(idx + 1, idx, nums, dp);

        return dp[idx][prev_idx + 1] = max(take, not_take);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp);
    }
};