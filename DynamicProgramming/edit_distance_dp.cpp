/*

For given strings of len m and n
make 2D matrix say dp of size m+1, n+1

dp[i][j]: represents edit distance for 
substring s1[0...i-1 ] and s2[0...j-1]

referring to recursive code

if n == 0, return m
so if i = 0 then edit distance = j
and if j = 0 then edit distance = i

we are going to fill 2D array using recursion logic
if(s1[i-1] == s2[j-1])
    dp[i][j] = dp[i-1][j-1]
else 
    // take min of up, diagonal, left
    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
*/

#include <iostream>
using namespace std;

int editDistance(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];

    // first col and ith row for s2=""
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;

    // first row and jth col for s1=""
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    string s1 = "SATURDAY", s2 = "SUNDAY";
    cout << editDistance(s1, s2, s1.length(), s2.length());
    return 0;
}

/*
op: 3

Time: theta(m) + theta(n) + theta(n*m)
Space: O(m*n)
*/