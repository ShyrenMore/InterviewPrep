/*
problem link: https://leetcode.com/problems/longest-common-subsequence/
*/
#include <iostream>
#include <vector>
using namespace std;
class RecSolution
{
public:
    int f(int idx1, int idx2, string text1, string text2)
    {
        if (idx1 < 0 || idx2 < 0)
            return 0;

        if (text1[idx1] == text2[idx2])
        {
            int match = 1 + f(idx1 - 1, idx2 - 1, text1, text2);
            return match;
        }

        int not_match = 0 + max(f(idx1, idx2 - 1, text1, text2), f(idx1 - 1, idx2, text1, text2));
        return not_match;
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        return f(n - 1, m - 1, text1, text2);
    }
};

class MemoSolution
{
public:
    int f(int idx1, int idx2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (idx1 < 0 || idx2 < 0)
            return 0;
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if (text1[idx1] == text2[idx2])
        {
            int match = 1 + f(idx1 - 1, idx2 - 1, text1, text2, dp);
            return dp[idx1][idx2] = match;
        }

        int not_match = 0 + max(f(idx1, idx2 - 1, text1, text2, dp), f(idx1 - 1, idx2, text1, text2, dp));
        return dp[idx1][idx2] = not_match;
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, text1, text2, dp);
    }
};

class Tabulation{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        // base case:
        for (int i = 0; i < n; i++)
            dp[i][0] = 0;
        for (int i = 0; i < n; i++)
            dp[0][i] = 0;

        for (int idx1 = 1; idx1 < n; idx1++)
            for (int idx2 = 1; idx2 < m; idx2++)
            {
                if (text1[idx1] == text2[idx2])
                {
                    int match = 1 + dp[idx1 - 1][idx2 - 1];
                    dp[idx1][idx2] = match;
                }

                int not_match = 0 + max(dp[idx1][idx2 - 1], dp[idx1 - 1][idx2]);
                dp[idx1][idx2] = not_match;
            }

        return dp[n + 1][m + 1];
    }
};