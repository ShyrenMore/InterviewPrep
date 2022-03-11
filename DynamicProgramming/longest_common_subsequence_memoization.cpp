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
In the recursion tree we found one overlapping sub-problems  i.e lcs("AX", "B")

Time for optimising naive sol using DP
let's try memoization
we need memo table of size m and n, initialised with any -ve number
int memo[m+1][n+1] = {-1, -1...-1}

now before every recursive call we check if we have already computed the memo table
i.e if(memo[m][n] != -1)
        return memo[m][n]

otherwise we store the result and do recursive call

let's first deal with base cases
if(m==0 || n==0)
    memo[m][n] = 0;

now the actual recursion
if(s1[m-1] == s2[n-1])
    memo[m][n] = 1 + lcs(s1, s2, m-1, n-1);
else
    memo[m][n] =  max(lcs(s1, s2, m, n-1), lcs(s1, s2, m-1, n));

at the end we return memo[m][n];
*/

const int M = 5;
const int N = 5;
int memo[M+1][N+1];

int lcs(string s1, string s2, int m, int n)
{
    if(memo[m][n] != -1)
        return memo[m][n];
    
    if(m==0 || n==0)
        memo[m][n] = 0;
    
    else
    {
        if (s1[m-1] == s2[n-1])
            memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1);
        else
            memo[m][n] = max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
    }

    return memo[m][n]; 
}

/*

Time: theta(mn) 
Space: O(1)

*/

int main()
{
    memset(memo, -1, M *N * sizeof(int));
    string s1 = "AXYZ";
    string s2 = "BAZ";

    cout << lcs(s1, s2, s1.length(), s2.length());
    return 0;
}

