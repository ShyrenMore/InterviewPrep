#include <bits/stdc++.h>
using namespace std;

/*
Link: https://leetcode.com/problems/rotting-oranges/

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange
*/

class Solution
{   
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // {{r, c}, time}
        queue < pair<pair<int, int>, int>> Q;
        vector<vector<int>> visited(n, vector<int> (m, 0));

        // at time 0, push rotten orange present initially
        for (int r = 0; r < n; r++){
            for (int c = 0; c < m; c++){
                if(grid[r][c] == 2){
                    Q.push({{r, c}, 0});
                    visited[r][c] = 2;
                }
            }
        }

        int time = 0;
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};
        while(!Q.empty())
        {
            int row = Q.front().first.first;
            int col = Q.front().first.second;
            int t = Q.front().second;
            time = max(t, time);
            Q.pop();

            // row: -1, 0, +1, 0
            // col: 0, +1, 0, -1
            // (row-1, col); (row, col+1); (row+1, col); (row, col-1)

            for (int i = 0; i < 4; i++)
            {
                int neighbour_row = row + delta_row[i];
                int neighbour_col = col + delta_col[i];

                // for each neighbour check boundary
                if (neighbour_row >= 0 && neighbour_row < n && neighbour_col >= 0 && neighbour_col < m)
                {
                    // check if orange is fresh and not prev rotten
                    if (grid[neighbour_row][neighbour_col] == 1 && visited[neighbour_row][neighbour_col]!=2)
                    {
                        visited[neighbour_row][neighbour_col] = 2;
                        Q.push({{neighbour_row, neighbour_col}, t+1});
                    }
                }
            }
        }

        // check if all are rotten
        for (int r = 0; r < n; r++){
            for (int c = 0; c < m; c++){
                if(visited[r][c] != 2 && grid[r][c] == 1)
                    return -1;
            }
        }

        return time;
    }
};