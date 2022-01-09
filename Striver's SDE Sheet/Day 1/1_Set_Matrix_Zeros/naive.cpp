/*

Q: Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

Ask: range of values

Assume all values > 0

We traverse the matrix, we get 0, we traverse entire row and column and place a value say (-1) that cannot be part of matrix

after this change -1 to 0

Time: Linear traversal will take (n*m), for every row and col traversal will take (n+m), 
total = n*m + (n+m)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    // setting row as -1
                    for (int c = 0; c < m; c++)
                        if (matrix[i][c]!=0)
                            matrix[i][c] = '-1';

                    for (int r = 0; r < n; r++)
                        if(matrix[r][j]!=0)
                            matrix[r][j] = '-1';
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '-1')
                    matrix[i][j] = 0;
            }
        }
    }
};