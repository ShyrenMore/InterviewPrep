/*
problem link: https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284

Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.
*/

#include <iostream>
#include <vector>
using namespace std;

class RecursiveSol{
public:
    int f(int idx, int len, vector<int> &price)
    {
        if(idx == 0)
            return price[0] * len;
        
        int not_take = 0 + f(idx - 1, len, price);
        int take = -1e9;
        if(idx+1 <= len)
            take = price[idx] + f(idx, len - (idx + 1), price);

        return max(not_take, take);
    }

    int cutRod(vector<int> &price, int n)
    {
        return f(n - 1, n, price);
    }
};

class MemoSol
{
public:
    int f(int idx, int len, vector<int> &price, vector<vector<int>> &dp)
    {
        if (idx == 0)
            return price[0] * len;

        if(dp[idx][len]!=-1)
            return dp[idx][len];

        int not_take = 0 + f(idx - 1, len, price, dp);
        int take = -1e9;
        if (idx + 1 <= len)
            take = price[idx] + f(idx, len - (idx + 1), price, dp);

        return dp[idx][len] = max(not_take, take);
    }

    int cutRod(vector<int> &price, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(n - 1, n, price, dp);
    }
};

class TabulationSol{
public:
    int cutRod(vector<int> &price, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        for (int i = 0; i <= n; i++)
            dp[0][i] = i * price[0];

        for (int idx = 1; idx < n; idx++)
            for (int len = 0; len <= n; len++)
            {
                int not_take = 0 + dp[idx - 1][len];
                int take = -1e9;
                if (idx + 1 <= len)
                    take = price[idx] + dp[idx][len - (idx + 1)];

                dp[idx][len] = max(not_take, take);
            }

        return dp[n-1][n];
    }
};