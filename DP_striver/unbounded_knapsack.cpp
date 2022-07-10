/*
link: https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029

You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with weight capacity ‘W’.
You need to fill the knapsack with the items in such a way that you get the maximum profit.
You are allowed to take one item multiple times.

Let us say we have 'N' = 3 items and a knapsack of capacity 'W' =  10
'PROFIT' = { 5, 11, 13 }
'WEIGHT' = { 2, 4, 6 }
op: 27
*/

#include <iostream>
#include <vector>
using namespace std;

class RecurSolution{
public:
    int f(int idx, int W, vector<int> &weight, vector<int> &value)
    {
        if (idx == 0)
        {
            if (weight[idx] <= W)
                return (W/weight[0])*value[0];
            else
                return 0;
        }

        int not_pick = f(idx - 1, W, weight, value);
        int pick = -1e9;
        if (weight[idx] <= W)
            pick = value[idx] + f(idx, W - weight[idx], weight, value);

        return max(pick, not_pick);
    }

    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        return f(n - 1, w, weight, profit);
    }
};

class MemoSol{
public:
    int f(int idx, int W, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (weight[idx] <= W)
                return (W / weight[0]) * value[0];
            else
                return 0;
        }
        if (dp[idx][W] != -1)
            return dp[idx][W];

        int not_pick = f(idx - 1, W, weight, value, dp);
        int pick = -1e9;
        if (weight[idx] <= W)
            pick = value[idx] + f(idx, W - weight[idx], weight, value, dp);

        return dp[idx][W] = max(pick, not_pick);
    }

    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
        return f(n - 1, w, weight, profit, dp);
    }
};

class Tabulation{
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        vector<vector<int>> dp(n, vector<int>(w + 1, 0));
        for (int i = weight[0]; i <= w; i++)
            dp[0][i] = ((int)i / weight[0]) * profit[0];
        

        for (int idx = 1; idx < n; idx++)
        {
            for (int wt = 0; wt <= w; wt++)
            {
                int not_pick = dp[idx - 1][wt];
                int pick = -1e9;
                if (weight[idx] <= wt)
                    pick = profit[idx] + dp[idx][wt - weight[idx]];

                dp[idx][wt] = max(pick, not_pick);
            }
        }

        return dp[n - 1][w];
    }
};