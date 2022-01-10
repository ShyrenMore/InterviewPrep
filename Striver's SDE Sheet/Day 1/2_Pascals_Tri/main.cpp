/*
Given no of rows, print pascal's triangle

eg:
n=4
         1
       1   1
    1    2     1
  1   3     3     1

Initialise first row with 1
Observations:
For every row, first column and last column has value 1
For nth row there will be n-elements present

Given row and column no, tell the value of that position in Pascal's traingle
Ans: (r-1)C(c-1), Time: O(n), Space: O(1)

Another form of question is print nth row of Pascal's triangle
Ans:
4C0 = 1
4C1 = 4*(4C0)/1 = 4
4C2 = 3/2 * (4C1) = 6

// Calculate value of n*(n-1)*..*(n-k+1)
for(int i = 0; i < k; i++){
    res = res * (n-1);
    res /= (i+1);
}
Time: O(N)
*/

#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++){
            // for each row, +1 element
            r[i].resize(i + 1);

            // corner elements
            r[i][0] = r[i][i] = 1;

            for (int j = 0; j < i; j++)
            {
                // (j-1)th col + jth col
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
            }
        }

        return r;
    }
};