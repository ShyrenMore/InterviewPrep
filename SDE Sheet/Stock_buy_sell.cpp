#include <iostream>
#include <vector>
using namespace std;

/*
link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Approach: 
Maintain two vars: mini->minimum price of stock and profit->max profit after selling

Traverse the array from idx 1
- compare and take max profit b/w sold stock, existing profit
- if we find new minimum price, update existing min price for future ref

Time: O(N)
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int mini = prices[0], profit = 0;
        for (int i = 1; i < n; i++)
        {
            profit = max(prices[i] - mini, profit);
            mini = min(mini, prices[i]);
        }

        return profit;
    }
};