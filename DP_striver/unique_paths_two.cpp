/*
Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell.
A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0.
From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.

Consider the maze below :
0 0 0
0 -1 0
0 0 0

There are two ways to reach the bottom left corner -

(1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
(1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)

Hence the answer for the above test case is 2.

https://leetcode.com/problems/unique-paths-ii/

here instead of -1 it is 1
*/
#include <iostream>
#include <vector>
using namespace std;

// recursive sol
class Solution
{
public:
    int f(int r, int c, vector<vector<int>> &obstacleGrid)
    {
        if (r >= 0 && c >= 0 && obstacleGrid[r][c] == 1)
            return 0;
        if (r == 0 && c == 0)
            return 1;
        if (r < 0 || c < 0)
            return 0;

        int left = f(r, c - 1, obstacleGrid);
        int up = f(r - 1, c, obstacleGrid);

        return left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        return f(rows - 1, cols - 1, obstacleGrid);
    }
};

// memoization
class Solution
{
public:
    int f(int r, int c, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        if (r >= 0 && c >= 0 && obstacleGrid[r][c] == 1)
            return 0;
        if (r == 0 && c == 0)
            return 1;
        if (r < 0 || c < 0)
            return 0;
        if(dp[r][c]!=-1)
            return dp[r][c];

        int left = f(r, c - 1, obstacleGrid, dp);
        int up = f(r - 1, c, obstacleGrid, dp);

        return dp[r][c] = left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return f(rows - 1, cols - 1, obstacleGrid, dp);
    }
};

// tabulation
class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        int dp[rows][cols];
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
            {
                if (obstacleGrid[r][c] == 1 && r >= 0 && c >= 0)
                    dp[r][c] = 0;
                else if (r == 0 && c == 0)
                    dp[r][c] = 1;
                else
                {
                    int up = 0, left = 0;
                    if (r > 0)
                        up = dp[r - 1][c];
                    if (c > 0)
                        left = dp[r][c - 1];
                    dp[r][c] = up + left;
                }
            }
        return dp[rows - 1][cols - 1];
    }
};