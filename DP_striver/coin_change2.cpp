/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.

https://leetcode.com/problems/coin-change-2/
*/
#include <iostream>
#include <vector>
using namespace std;

class RecSolution
{
public:
    int f(int idx, int amount, vector<int> &coins)
    {
        if (idx == 0)
        {
            if (amount % coins[0] == 0)
                return 1;
            else
                return 0;
        }

        int not_pick = f(idx - 1, amount, coins);
        int pick = 0;
        if (coins[idx] <= amount)
            pick = f(idx, amount - coins[idx], coins);

        return (pick + not_pick);
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        int ans = f(n - 1, amount, coins);
        return ans;
    }
};

class MemoSolution
{
public:
    int f(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (amount % coins[0] == 0)
                return 1;
            else
                return 0;
        }
        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int not_pick = f(idx - 1, amount, coins, dp);
        int pick = 0;
        if (coins[idx] <= amount)
            pick = f(idx, amount - coins[idx], coins, dp);

        return dp[idx][amount] = (pick + not_pick);
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);
        return ans;
    }
};

class TabulationSolution{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++)
            if (i % coins[0] == 0)
                dp[0][i] = 1;
            else
                dp[0][i] = 0;

        for (int i = 1; i < n; i++)
        {
            for (int t = 0; t <= amount; t++)
            {
                int not_pick = dp[i - 1][t];
                int pick = 0;
                if (coins[i] <= t)
                    pick = dp[i][t - coins[i]];

                dp[i][t] = (pick + not_pick);
            }
        }

        int ans = dp[n - 1][amount];
        return ans;
    }
};