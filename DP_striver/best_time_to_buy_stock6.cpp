/*
problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
*/

#include <iostream>
#include <vector>
using namespace std;

class RecSolution
{
public:
    int f(int day, int canBuy, int n, vector<int> &prices, int fees)
    {
        if (day == n)
            return 0;
        int profit = 0;
        if (canBuy)
        {
            int buy = -prices[day] + f(day + 1, 0, n, prices, fees);
            int not_buy = 0 + f(day + 1, 1, n, prices, fees);
            profit = max(buy, not_buy);
        }
        else
        {
            int sell = prices[day] - fees + f(day + 1, 1, n, prices, fees);
            int not_sell = 0 + f(day + 1, 0, n, prices, fees);
            profit = max(sell, not_sell);
        }

        return profit;
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        return f(0, 1, n, prices, fee);
    }
};

class MemoSolution
{
public:
    int f(int day, int canBuy, int n, vector<int> &prices, vector<vector<int>> &dp, int fees)
    {
        if (day == n)
            return 0;

        if (dp[day][canBuy] != -1)
            return dp[day][canBuy];

        if (canBuy)
        {
            int buy = -prices[day] + f(day + 1, 0, n, prices, dp, fees);
            int not_buy = 0 + f(day + 1, 1, n, prices, dp, fees);
            dp[day][canBuy] = max(buy, not_buy);
        }
        else
        {
            int sell = prices[day] - fees + f(day + 1, 1, n, prices, dp, fees);
            int not_sell = 0 + f(day + 1, 0, n, prices, dp, fees);
            dp[day][canBuy] = max(sell, not_sell);
        }

        return dp[day][canBuy];
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return f(0, 1, n, prices, dp, fee);
    }
};

class TabulationSolution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        for (int day = n - 1; day >= 0; day--)
            for (int canBuy = 0; canBuy < 2; canBuy++)
            {
                if (canBuy)
                {
                    int buy = -prices[day] + dp[day + 1][0];
                    int not_buy = 0 + dp[day + 1][1];
                    dp[day][canBuy] = max(buy, not_buy);
                }
                else
                {
                    int sell = prices[day] - fee + dp[day + 1][1];
                    int not_sell = 0 + dp[day + 1][0];
                    dp[day][canBuy] = max(sell, not_sell);
                }
            }

        return dp[0][1];
    }
};