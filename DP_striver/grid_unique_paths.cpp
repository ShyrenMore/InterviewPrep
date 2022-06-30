#include <iostream>
#include <vector>
using namespace std;

/*
You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point ‘A’ to point ‘B’

To traverse in the matrix, you can either move Right or Down at each step.

You are give M and N values

ip: 2, 2
op: 2
exp: Path 1 = (0, 0) -> (0, 1) -> (1, 1)
Path 2 = (0, 0) -> (1, 0) -> (1, 1)
*/

// recursive sol

int f(int r, int c)
{
    if(r == 0 && c == 0)
        return 1;
    if (r<0 || c < 0)
        return 0;
    int left = f(r, c - 1);
    int up = f(r - 1, c);
    return up + left;
}

int uniquePaths(int m, int n)
{
    return f(m - 1, n - 1);
}

// memoization

int f_m(int r, int c, vector<vector<int>> &dp)
{
    if (r == 0 && c == 0)
        return 1;
    if (r < 0 || c < 0)
        return 0;
    if(dp[r][c]!=-1)
        return dp[r][c];

    int left = f_m(r, c - 1, dp);
    int up = f_m(r - 1, c, dp);
    return dp[r][c] = up + left;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f_m(m - 1, n - 1, dp);
}

// tabulation
int uniquePaths(int m, int n)
{
    int dp[n][m];
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
        {
            if(r == 0 && c == 0)
                dp[r][c] = 1;
            else 
            {
                int up = 0, left = 0;
                if(r > 0)
                    up = dp[r - 1][c];
                if (c>0)
                    left = dp[r][c - 1];
                dp[r][c] = up + left;
            }
        }
    return dp[n - 1][m - 1];
}