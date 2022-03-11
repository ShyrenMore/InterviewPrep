#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*
given two strings
find length of longest common subsequence (LCS)
or
find maximum length of the common appearing subsequence in both strings

ip:
s1 = "ABCDGH"
s2 = "AEDFHR"
op: 3
explnation: ADH

ip:
s1 = "AGGTAB"
s2 = "GXTXAYB"
op: 4
explnation: GTAB

ip:
s1 = "XYZ"
s2 = "XYZ"
op: 3
explnation: XYZ

ip:
s1 = "ABC"
s2 = "XY"
op: 0
explnation: no common char

*/

/*
In tabulation, we create an array of size m+1 and n+1, 
no need for initialisation
we fill this array in bottom up manner 

dp[i][j] is going to store length of LCS of s1[0..i-1] and s2[0..j-1]

first thing we know if any string is of 0 length it's subsequence will also be zeros
so fill first row and column with 0s 

now we fill remaining places by the foll logic
if s1[i-1] == s2[j-1]
    dp[i][j] = 1 + dp[i-1][j-1]
else 
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
*/

int lcs(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    int dp[m + 1][n + 1];

    // fill first col with 0
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;

    // fill first row with 0
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    // start filling second row, column-by-column
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[m][n];
}

int main()
{
    string s1 = "AXYZ";
    string s2 = "BAZ";

    cout << lcs(s1, s2);
    return 0;
}

/*

Time: theta(m*n)
Space: theta(m*n)
*/