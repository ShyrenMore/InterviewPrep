/*
Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. Each point in the grid has some cost associated with it.
Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.

ip: n and m
n*m grid
op: print the minimum sum of the path from top left to bottom right.

ip:
2 3
5 9 6
11 5 2
op: 21
exp: 5 -> 9 -> 5 -> 2

ip:
1 1
5
op: 5

*/
#include <iostream>
#include <vector>
using namespace std;

// recursion
class Solution
{
public:
    int f(int r, int c, vector<vector<int>> &grid)
    {
        if (r == 0 && c == 0)
            return grid[0][0];

        if (r < 0 || c < 0)
            return 1e9;

        int up = grid[r][c] + f(r - 1, c, grid);
        int left = grid[r][c] + f(r, c - 1, grid);

        return min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        return f(n - 1, m - 1, grid);
    }
};

// memoization
class Solution
{
public:
    int f(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (r == 0 && c == 0)
            return grid[0][0];

        if (r < 0 || c < 0)
            return 1e9;

        if (dp[r][c] != -1)
            return dp[r][c];

        int up = grid[r][c] + f(r - 1, c, grid, dp);
        int left = grid[r][c] + f(r, c - 1, grid, dp);

        return dp[r][c] = min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, grid, dp);
    }
};

// tabulation
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (row == 0 && col == 0)
                    dp[row][col] = grid[0][0];
                else
                {
                    int up = grid[row][col], left = grid[row][col];
                    if (row > 0)
                        up += dp[row - 1][col];
                    else
                        up += 1e9;

                    if (col > 0)
                        left += dp[row][col - 1];
                    else
                        left += 1e9;

                    dp[row][col] = min(up, left);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};