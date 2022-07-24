/*
problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
*/
#include <iostream>
#include <vector>
using namespace std;

class RecSolution
{
public:
    int f(int day, bool canBuy, int cap, vector<int> &prices, int n)
    {
        if (day == n)
            return 0;

        if (cap == 0)
            return 0;

        int profit = 0;
        if (canBuy)
        {
            int buy = -prices[day] + f(day + 1, 0, cap, prices, n);
            int not_buy = 0 + f(day + 1, 1, cap, prices, n);
            profit = max(buy, not_buy);
        }
        else
        {
            int sell = prices[day] + f(day + 1, 1, cap - 1, prices, n);
            int not_sell = 0 + f(day + 1, 0, cap, prices, n);
            profit = max(sell, not_sell);
        }

        return profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        return f(0, 1, k, prices, n);
    }
};

class MemoSolution
{
public:
    int f(int day, bool canBuy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
    {
        if (day == n)
            return 0;

        if (cap == 0)
            return 0;

        if (dp[day][canBuy][cap] != -1)
            return dp[day][canBuy][cap];

        int profit = 0;
        if (canBuy)
        {
            int buy = -prices[day] + f(day + 1, 0, cap, prices, n, dp);
            int not_buy = 0 + f(day + 1, 1, cap, prices, n, dp);
            dp[day][canBuy][cap] = max(buy, not_buy);
        }
        else
        {
            int sell = prices[day] + f(day + 1, 1, cap - 1, prices, n, dp);
            int not_sell = 0 + f(day + 1, 0, cap, prices, n, dp);
            dp[day][canBuy][cap] = max(sell, not_sell);
        }

        return dp[day][canBuy][cap];
    }

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // day, canbuy, cap
        // n*2*k+1
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0, 1, k, prices, n, dp);
    }
};

class Tabulation
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // day, canbuy, cap
        // n*2*k+1
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for (int day = n - 1; day >= 0; day--)
            for (int canBuy = 0; canBuy < 2; canBuy++)
                for (int cap = 1; cap <= k; cap++)
                {
                    if (canBuy)
                    {
                        // int buy = -prices[day] + f(day + 1, 0, cap, prices, n, dp);
                        int buy = -prices[day] + dp[day + 1][0][cap];
                        int not_buy = 0 + dp[day + 1][1][cap];
                        dp[day][canBuy][cap] = max(buy, not_buy);
                    }
                    else
                    {
                        int sell = prices[day] + dp[day + 1][1][cap - 1];
                        int not_sell = 0 + dp[day + 1][0][cap];
                        dp[day][canBuy][cap] = max(sell, not_sell);
                    }
                }

        return dp[0][1][k];
    }
};