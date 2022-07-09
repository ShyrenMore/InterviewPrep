/*
Problem link: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

WORKS FOR ONLY +VE NUMS

You are given an integer array nums of 2 * n integers.
You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays.
To partition nums, put each element of nums into one of the two arrays.

Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Eff_Solution
{
public:
    // the tabulation is taken from Subset sum equal to K

    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int total_sum = 0;
        for(auto el: nums)
            total_sum += el;
        int k = total_sum;
        
        // tabulation code starts here
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= k)
            dp[0][nums[0]] = true;

        for (int idx = 1; idx < n; idx++)
        {
            for (int tgt = 1; tgt <= k; tgt++)
            {
                bool notTake = dp[idx - 1][tgt];
                bool take = false;
                if (nums[idx] <= tgt)
                    take = dp[idx - 1][tgt - nums[idx]];
                dp[idx][tgt] = (take | notTake);
            }
        }
        // tabulation code ends here
        
        int mini = 1e9;
        for (int s1 = 0; s1 <= k; s1++)
        {
            if(dp[n-1][s1])
            {
                int s2 = total_sum - s1;
                mini = min(mini, (int)fabs(s2 - s1));
            }
        }

        return mini;
    }
};