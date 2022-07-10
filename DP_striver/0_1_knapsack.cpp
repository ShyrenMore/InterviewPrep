/*
problem link: https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

A thief is robbing a store and can carry a maximal weight of W into his knapsack. 
There are N items and the ith item weighs wi and is of value vi. 
Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.
*/

#include <iostream>
#include <vector>
using namespace std;

class RecSolution{

    int f(int idx, int W, vector<int> &weight, vector<int> &value)
    {
        if(idx == 0)
        {
            if(weight[idx]<=W)
                return value[0];
            else
                return 0;
        }

        int not_pick = f(idx - 1, W, weight, value);
        int pick = -1e9;
        if(weight[idx] <= W)
            pick = value[idx] + f(idx - 1, W - weight[idx], weight, value);

        return max(pick, not_pick);
    }

    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        // Write your code here
        return f(n - 1, maxWeight, weight, value);
    }
};

class MemoSolution{

    int f(int idx, int W, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (weight[idx] <= W)
                return value[0];
            else
                return 0;
        }

        if(dp[idx][W]!=-1)
            return dp[idx][W];

        int not_pick = f(idx - 1, W, weight, value, dp);
        int pick = -1e9;
        if (weight[idx] <= W)
            pick = value[idx] + f(idx - 1, W - weight[idx], weight, value, dp);

        return dp[idx][W] = max(pick, not_pick);
    }

    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        // Write your code here
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
        return f(n - 1, maxWeight, weight, value, dp);
    }
};

class TabulationSol{
public:
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        // DONT INITIALISE with -1
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

        for (int i = weight[0]; i <= maxWeight; i++)
            dp[0][i] = value[0];

        for (int idx = 1; idx < n; idx++)
        {
            for (int wt = 0; wt <= maxWeight; wt++)
            {
                int not_pick = dp[idx - 1][wt];
                int pick = -1e9;
                if (weight[idx] <= wt)
                    pick = value[idx] + dp[idx - 1][wt - weight[idx]];

                dp[idx][wt] = max(pick, not_pick);
            }
        }

        return dp[n - 1][maxWeight];
    }
};