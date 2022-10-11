#include <bits/stdc++.h>
using namespace std;

/*
Link: https://leetcode.com/problems/surrounded-regions/
Video link: https://youtu.be/BtdgAys4yMk
*/

class Solution
{

private:
    void dfs(int row, int col,  vector<vector<int>> &visited, vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        visited[row][col] = 1;
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int neighbour_row = row + delta_row[i];
            int neighbour_col = col + delta_col[i];

            if(neighbour_row >=0 and neighbour_row < n and neighbour_col >= 0 and neighbour_col < m)
            {
                if(!visited[neighbour_row][neighbour_col]  and board[neighbour_row][neighbour_col] == 'O')
                    dfs(neighbour_row, neighbour_col, visited, board);
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // traverse first row, last row
        for (int c = 0; c < m; c++)
        {
            // first row
            if(!visited[0][c] and board[0][c] == 'O')
                dfs(0, c, visited, board);

            if (!visited[n - 1][c] and board[n-1][c] == 'O')
                dfs(n-1, c, visited, board);
        }
        // traverse first col, last col
        for (int r = 0; r < n; r++)
        {
            // first col
            if(!visited[r][0] and board[r][0] == 'O')
                dfs(r, 0, visited, board);

            if (!visited[r][m-1] and board[r][m-1] == 'O')
                dfs(r, m-1, visited, board);
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if(!visited[i][j] and board[i][j] == 'O')
                    board[i][j] = 'X';
            }
    }
};