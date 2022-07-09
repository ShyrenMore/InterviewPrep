/*
problem link: https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
*/

#include <iostream>
#include <vector>
using namespace std;

class Recursive_Sol{
public:
    int f(vector<int> &arr, int idx, int target)
    {
        if (target == 0)
            return 1;

        if (idx == 0)
            return (arr[0] == target);

        int not_take = f(arr, idx - 1, target);
        int take = 0;
        if (arr[idx] <= target)
            take = f(arr, idx - 1, target - arr[idx]);

        return (take | not_take);
    }

    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        return f(arr, n - 1, k);
    }
};

class Memo_Sol{
public:
    int f(vector<vector<int>> &dp, vector<int> &arr, int idx, int target)
    {
        if (target == 0)
            return 1;

        if (idx == 0)
            return (arr[0] == target);

        if (dp[idx][target] != -1)
            return dp[idx][target];

        int not_take = f(dp, arr, idx - 1, target);
        int take = 0;
        if (arr[idx] <= target)
            take = f(dp, arr, idx - 1, target - arr[idx]);

        return dp[idx][target] = (take | not_take);
    }

    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return f(dp, arr, n - 1, k);
    }
};

class Tabulation_Sol{
public:
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // if target == 0 return true;
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        // if idx == 0 return target == arr[0]
        if (arr[0] <= k)
            dp[0][arr[0]] = true;

        for (int idx = 1; idx < n; idx++)
        {
            for (int tgt = 0; tgt <= k; tgt++)
            {
                bool notTake = dp[idx - 1][tgt];
                bool take = false;
                if (arr[idx] <= tgt)
                    take = dp[idx - 1][tgt - arr[idx]];
                dp[idx][tgt] = (take | notTake);
            }
        }

        return dp[n - 1][k];
    }
};

