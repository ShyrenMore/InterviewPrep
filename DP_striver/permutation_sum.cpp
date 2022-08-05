/*
problem link: https://leetcode.com/problems/combination-sum-iv/
this is basically subset sum  == k
but 1,1,2 is different than 1,2,1
so we need to count both
hence for each subproblem, instead of just visiting idx-1, we need to visit entire array
*/

#include <iostream>
#include <vector>
using namespace std;

class RecSolution
{
public:
    int f(int target, vector<int> &nums)
    {
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;

        int ways = 0;
        for (int num : nums)
            ways += f(target - num, nums);

        return ways;
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        // for every sub-problem, consider entire array
        return f(target, nums);
    }
};

class MemoSolution
{
public:
    int f(int target, vector<int> &nums, vector<int> &dp)
    {
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;
        if (dp[target] != -1)
            return dp[target];

        int ways = 0;
        for (int num : nums)
            ways += f(target - num, nums, dp);

        return dp[target] = ways;
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        // for every sub-problem, consider entire array
        vector<int> dp(target + 1, -1);
        return f(target, nums, dp);
    }
};