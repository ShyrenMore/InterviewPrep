/*
given n and arr
return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

ip: 3
1 2 4
op: 5 (1+4)

ip: 4
2 1 4 9
op: 11 (9+2)

https://leetcode.com/problems/house-robber/
*/

#include <iostream>
#include <vector>
using namespace std;

// recursive sol:
class RecursiveSolution
{
public:
    int f(int idx, vector<int> &nums)
    {
        if (idx == 0)
            return nums[idx];

        if (idx < 0)
            return 0;

        int pickup = nums[idx] + f(idx - 2, nums);
        int notPickup = 0 + f(idx - 1, nums);

        return max(pickup, notPickup);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        return f(n - 1, nums);
    }
};

// memoization
class MemoSolution
{
public:
    int f(int idx, vector<int> &nums, vector<int> &dp)
    {
        if (idx == 0)
            return nums[idx];

        if (idx < 0)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int pickup = nums[idx] + f(idx - 2, nums, dp);
        int notPickup = 0 + f(idx - 1, nums, dp);

        return dp[idx] = max(pickup, notPickup);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1, nums, dp);
    }
};