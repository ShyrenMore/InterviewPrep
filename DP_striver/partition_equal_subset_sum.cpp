/*
problem link: https://leetcode.com/problems/partition-equal-subset-sum/

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

#include <iostream>
#include <vector>
using namespace std;

class Rec_Solution
{
public:
    bool f(vector<int> &nums, int idx, int target)
    {
        if (target == 0)
            return 1;

        if (idx == 0)
            return (target == nums[0]);

        int not_take = f(nums, idx - 1, target);
        int take = 0;
        if (nums[idx] <= target)
            take = f(nums, idx - 1, target - nums[idx]);

        return (take | not_take);
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto el : nums)
            sum += el;

        if (sum & 1)
            return 0;

        int n = nums.size();
        return f(nums, n - 1, sum / 2);
    }
};

class Memo_Solution
{
public:
    bool f(vector<vector<int>> &dp, vector<int> &nums, int idx, int target)
    {
        if (target == 0)
            return 1;

        if (idx == 0)
            return (target == nums[0]);

        if (dp[idx][target] != -1)
            return dp[idx][target];

        int not_take = f(dp, nums, idx - 1, target);
        int take = 0;
        if (nums[idx] <= target)
            take = f(dp, nums, idx - 1, target - nums[idx]);

        return dp[idx][target] = (take | not_take);
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto el : nums)
            sum += el;

        if (sum & 1)
            return 0;

        int n = nums.size();
        int tgt = sum / 2;
        vector<vector<int>> dp(n, vector<int>(tgt + 1, -1));
        return f(dp, nums, n - 1, sum / 2);
    }
};

class Tabulation_Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto el : nums)
            sum += el;

        if (sum & 1)
            return 0;

        int n = nums.size();
        int k = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // if target == 0 return true
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        // mark where arr[0] == target as true
        if (nums[0] <= k)
            dp[0][nums[0]] = true;

        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 0; target <= k; target++)
            {
                int not_take = dp[idx - 1][target];
                int take = 0;
                if (nums[idx] <= target)
                    take = dp[idx - 1][target - nums[idx]];

                dp[idx][target] = (take | not_take);
            }
        }

        return dp[n - 1][k];
    }
};