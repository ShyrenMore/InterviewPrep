#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);

        // initialising string like we do for vector
        string s(n, '.');

        // s is single row
        // so we will put s in board n times, so we have n*n arrangement
        for (int i = 0; i < n; i++)
            board[i] = s;

        solve(0, board, ans, n);

        return ans;
    }

    void solve(int col, vector<string> &board, vector<vector<string>>&ans, int n)
    {
        // base case: when we reach n-1th col
        if(col == n)
        {
            // store ans
            ans.push_back(board);
            return;
        }

        // try every row
        for (int row = 0; row < n; row++)
        {
            if(isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                
                // recursive call for next column
                solve(col + 1, board, ans, n);

                // if recursion ends midway, backtrack
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int uprow = row, upcol = col;
        int lorow = row, locol = col;

        // check entire upper-left diagonal for safety
        while(uprow >= 0 && upcol >= 0)
        {
            if(board[uprow][upcol] == 'Q')
                return false;
            
            // go to next upper left cell i,e row-1 and col-1
            --uprow;
            --upcol;
        }

        // check entire lower-left diagonal for safety
        while(lorow < n && locol>=0)
        {
            if (board[lorow][locol] == 'Q')
                return false;

            ++lorow;
            --locol;
        }

        // check left row
        while(col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            --col;
        }

        return true;
    }
};