#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};
        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + dx[i];
            int ncol = c + dy[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                if (!vis[nrow][ncol] && grid[nrow][ncol])
                    dfs(nrow, ncol, vis, grid);
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // identifying 1s(sources) on the boundaries

        // 1st row
        for (int i = 0; i < m; i++)
            if (vis[0][i] == 0 && grid[0][i])
                dfs(0, i, vis, grid);
        // last row
        for (int i = 0; i < m; i++)
            if (vis[n - 1][i] == 0 && grid[n - 1][i])
                dfs(n - 1, i, vis, grid);

        // 1st col
        for (int i = 0; i < n; i++)
            if (vis[i][0] == 0 && grid[i][0])
                dfs(i, 0, vis, grid);

        // last col
        for (int i = 0; i < n; i++)
            if (vis[i][m - 1] == 0 && grid[i][m - 1])
                dfs(i, m - 1, vis, grid);

        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j] && grid[i][j])
                    ++cnt;
        return cnt;
    }
};
