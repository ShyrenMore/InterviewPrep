/*
problem link: https://leetcode.com/problems/target-sum/
The below efficient tabulation code is taken from
Count no of Partitions with given difference

Return the number of different expressions that you can build, which evaluates to target.
*/

#include <iostream>
#include <vector>
using namespace std;

class TabulationSol
{
public:
    int mod = (int)1e9 + 7;
    int f(vector<int> &num, int tar)
    {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
        if (num[0] == 0)
            dp[0][0] = 2; // 2 cases -pick and not pick
        else
            dp[0][0] = 1; // 1 case - not pick

        if (num[0] != 0 && num[0] <= tar)
            dp[0][num[0]] = 1; // 1 case -pick

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= tar; target++)
            {
                int notTaken = dp[ind - 1][target];
                int taken = 0;
                if (num[ind] <= target)
                    taken = dp[ind - 1][target - num[ind]];
                dp[ind][target] = (notTaken + taken) % mod;
            }
        }
        return dp[n - 1][tar];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int totSum = 0;
        for (int i = 0; i < nums.size(); i++)
            totSum += nums[i];

        // Checking for edge cases
        if (totSum - target < 0)
            return 0;
        if ((totSum - target) % 2 == 1)
            return 0;

        int s2 = (totSum - target) / 2;
        return f(nums, s2);
    }
};