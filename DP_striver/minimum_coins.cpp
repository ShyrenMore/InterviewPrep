/*
problem link: https://leetcode.com/problems/coin-change/

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
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
                return amount / coins[0];
            else
                return 1e9;
        }

        int not_pick = f(idx - 1, amount, coins);
        int pick = 1e9;
        if (coins[idx] <= amount)
            pick = 1 + f(idx, amount - coins[idx], coins);

        return min(pick, not_pick);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int ans = f(n - 1, amount, coins);
        return (ans == 1e9 ? -1 : ans);
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
                return amount / coins[0];
            else
                return 1e9;
        }

        if(dp[idx][amount] != -1)
            return dp[idx][amount];

        int not_pick = f(idx - 1, amount, coins, dp);
        int pick = 1e9;
        if (coins[idx] <= amount)
            pick = 1 + f(idx, amount - coins[idx], coins, dp);

        return dp[idx][amount] = min(pick, not_pick);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);
        return (ans == 1e9 ? -1 : ans);
    }
};

class Tabulation{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        for (int i = 0; i <= amount; i++)
            if(i%coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;

        for (int i = 1; i < n; i++)
        {
            for (int t = 0; t <= amount; t++)
            {
                int not_pick = dp[i - 1][t];
                int pick = 1e9;
                if (coins[i] <= t)
                    pick = 1 + dp[i][t - coins[i]];

                dp[i][t] = min(pick, not_pick);
            }
        }

        int ans = dp[n - 1][amount];
        return (ans == 1e9 ? -1 : ans);
    }
};