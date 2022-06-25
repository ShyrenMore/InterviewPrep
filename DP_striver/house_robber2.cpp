/*
Given n and circular array
print a single line containing a single integer denoting the maximum sum

ip: 3
2 3 2
op: 3
exp: if it was not circular arr, ans would be 2+2

ip: 5
1 5 1 2 6
op: 11
exp: 5 and 6

ip: 4
1 3 2 1
op: 4
exp: 3, 1
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

        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> temp1(nums.begin(), nums.end() - 1);
        vector<int> temp2(nums.begin() + 1, nums.end());

        int ans1 = f(temp1.size() - 1, temp1);
        int ans2 = f(temp2.size() - 1, temp2);

        return max(ans1, ans2);
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

        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> temp1(nums.begin(), nums.end() - 1);
        vector<int> temp2(nums.begin() + 1, nums.end());

        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);
        int ans1 = f(temp1.size() - 1, temp1, dp1);
        int ans2 = f(temp2.size() - 1, temp2, dp2);

        return max(ans1, ans2);
    }
};