/*
problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
*/

#include <iostream>
#include <vector>
using namespace std;

class RecSolution
{
public:
    int f(int day, int canBuy, int n, vector<int> &prices)
    {
        if(day == n || day > n)
            return 0;
        int profit = 0;
        if(canBuy)
        {
            int buy = -prices[day] + f(day + 1, 0, n, prices);
            int not_buy = 0 + f(day + 1, 1, n, prices);
            profit = max(buy, not_buy);
        }
        else 
        {
            int sell = prices[day] + f(day + 2, 1, n, prices);
            int not_sell = 0 + f(day + 1, 0, n, prices);
            profit = max(sell, not_sell);
        }

        return profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return f(0, 1, n, prices);
    }
};

class MemoSolution
{
public:
    int f(int day, int canBuy, int n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if(day == n || day > n)
            return 0;

        if(dp[day][canBuy] != -1)
            return dp[day][canBuy];

        if(canBuy)
        {
            int buy = -prices[day] + f(day + 1, 0, n, prices, dp);
            int not_buy = 0 + f(day + 1, 1, n, prices, dp);
            dp[day][canBuy] = max(buy, not_buy);
        }
        else 
        {
            int sell = prices[day] + f(day + 2, 1, n, prices, dp);
            int not_sell = 0 + f(day + 1, 0, n, prices, dp);
            dp[day][canBuy] = max(sell, not_sell);
        }

        return dp[day][canBuy];
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return f(0, 1, n, prices, dp);
    }
};

class TabulationSolution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        // return f(0, 1, n, prices, dp);

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
                    int sell = prices[day] + dp[day + 2][1];
                    int not_sell = 0 + dp[day + 1][0];
                    dp[day][canBuy] = max(sell, not_sell);
                }
            }

        return dp[0][1];
    }
};