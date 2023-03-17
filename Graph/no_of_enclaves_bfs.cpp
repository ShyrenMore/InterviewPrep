#include <bits/stdc++.h>
using namespace std;

/*
Link: https://leetcode.com/problems/number-of-enclaves/
Video link: https://youtu.be/rxKcepXQgU4
*/

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // rather traversing each boundary indivodually
        // traverse entire matrix and apply specific condition
        for (int r = 0; r < n; r++){
            for (int c = 0; c < m; c++) {
                if (r == 0 || c == 0 || r == n - 1 || c == m - 1)
                {
                    if (grid[r][c] == 1)
                    {
                        q.push({r, c});
                        visited[r][c] = 1;
                    }
                }
            }
        }

        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++){
                int nrow = r + delta_row[i];
                int ncol = c + delta_col[i];
                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m)
                {
                    if(!visited[nrow][ncol] and grid[nrow][ncol])
                    {
                        q.push({nrow, ncol});
                        visited[nrow][ncol] = 1;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(grid[i][j] and !visited[i][j])
                    ++ans;
            }
        }

        return ans;
    }
};
