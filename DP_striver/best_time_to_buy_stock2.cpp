/*
problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

#include <iostream>
#include <vector>
using namespace std;

class RecSolution
{
public:
    int f(int idx, bool isBought, vector<int> &prices)
    {
        int profit = 0;
        int n = prices.size();
        if (idx == n)
            return 0;

        if (!isBought)
        {
            int buy = f(idx + 1, true, prices) - prices[idx];
            int not_buy = f(idx + 1, false, prices) - 0;
            profit = max(buy, not_buy);
        }
        else
        {
            int sell = f(idx + 1, false, prices) + prices[idx];
            int not_sell = f(idx + 1, true, prices);
            profit = max(sell, not_sell);
        }
        return profit;
    }

    int maxProfit(vector<int> &prices)
    {

        return f(0, false, prices);
    }
};

class MemoSolution
{
public:
    int f(int idx, bool isBought, vector<int> &prices, vector<vector<int>> &dp)
    {
        int profit = 0;
        int n = prices.size();
        if (idx == n)
            return 0;

        if (dp[idx][isBought] != -1)
            return dp[idx][isBought];

        if (!isBought)
        {
            int buy = f(idx + 1, true, prices, dp) - prices[idx];
            int not_buy = f(idx + 1, false, prices, dp) - 0;
            dp[idx][isBought] = max(buy, not_buy);
        }
        else
        {
            int sell = f(idx + 1, false, prices, dp) + prices[idx];
            int not_sell = f(idx + 1, true, prices, dp);
            dp[idx][isBought] = max(sell, not_sell);
        }
        return dp[idx][isBought];
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return f(0, false, prices, dp);
    }
};

class TabulationSolution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int b = 1; b >= 0; b--)
            {
                int profit = 0;
                if (!b)
                {
                    int buy = dp[idx + 1][1] - prices[idx];
                    int not_buy = dp[idx + 1][0] - 0;
                    profit = max(buy, not_buy);
                }
                else
                {
                    int sell = dp[idx + 1][0] + prices[idx];
                    int not_sell = dp[idx + 1][1] + 0;
                    profit = max(sell, not_sell);
                }

                dp[idx][b] = profit;
            }
        }

        return dp[0][0];
    }
};