#include <iostream>
#include <vector>
using namespace std;

/*

We maintain two dummy arrays, one for col and row
for this purpose, we maintain first row as column dummy arrays
and first column as row dummy array

we traverse the matrix, whenever we find 0, we simply put 0 in row and col index

we traverse the matrix again, we check if for mat[i][j], if dummy row array is 0 or col is also 0, 
we simply set mat[i][j] as 0 
that's our ans

Time: O(n*m + n*m)
Space: O(1)

*/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool col0 = true;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            // check 0th col value
            if(matrix[i][0] == 0)
                col0 = false;
            
            // traverse rest cols
            for (int j = 1; j < cols; j++)
            {
                // if 0 is found, set dummy index as 0
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }

        // lineraly traverse backwards
        for (int i = rows-1; i >= 0; i--)
        {
            for (int j = cols-1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }

            if(!col0)
                matrix[i][0] = 0;
        }
    }
};