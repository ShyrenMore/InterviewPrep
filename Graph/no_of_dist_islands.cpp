#include <bits/stdc++.h>
using namespace std;

/*
Link: https://youtu.be/7zmgQSJghpo
*/

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int base_x, int base_y)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        vec.push_back({row - base_x, col - base_y});

        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, -1, 0, +1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delta_row[i];
            int ncol = col + delta_col[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                // extra check for land/aanything goes here
                if (!vis[nrow][ncol] && grid[nrow][ncol])
                    dfs(nrow, ncol, vis, grid, vec, base_x, base_y);
                // DFS or BFS
                // dfs(neighbour_row, neighbour_col, visited, grid);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> s;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j])
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    s.insert(vec);
                }
            }
        }

        return s.size();
    }
};
